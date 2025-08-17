#!/usr/bin/python3
"""
Recursive function to count words in Reddit hot posts
"""
import requests
import re


def count_words(subreddit, word_list, word_counts=None, after=None):
    """
    Recursively queries Reddit API and counts keyword occurrences in hot post
    titles.

    Args:
        subreddit (str): The subreddit to query
        word_list (list): List of keywords to count
        word_counts (dict): Dictionary to store word counts (for recursion)
        after (str): Reddit API pagination parameter
    """
    # Initialize word_counts dictionary on first call
    if word_counts is None:
        word_counts = {}
        # Initialize all words from word_list (case-insensitive)
        for word in word_list:
            word_lower = word.lower()
            if word_lower in word_counts:
                word_counts[word_lower] = 0  # Reset if duplicate
            else:
                word_counts[word_lower] = 0

    # Build URL for Reddit API
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    # Set up headers to avoid being blocked
    headers = {
        'User-Agent': 'python:word_counter:v1.0 (by /u/student)'
    }

    # Add pagination parameter if provided
    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        # Make request to Reddit API
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False, timeout=10)

        # Check for redirects (invalid subreddit)
        if response.status_code == 302:
            return

        # Check for other error status codes
        if response.status_code != 200:
            return

        # Parse JSON response
        data = response.json()

        # Check if response has expected structure
        if 'data' not in data or 'children' not in data['data']:
            return

        posts = data['data']['children']

        # If no posts, we're done
        if not posts:
            # Print results only on the final call (when no more posts)
            if after is None or len(posts) == 0:
                print_results(word_counts)
            return

        # Process each post title
        for post in posts:
            if 'data' in post and 'title' in post['data']:
                title = post['data']['title']
                count_words_in_title(title, word_counts)

        # Get pagination info for next page
        next_after = data['data'].get('after')

        # If there are more pages, recurse
        if next_after:
            count_words(subreddit, word_list, word_counts, next_after)
        else:
            # This was the last page, print results
            print_results(word_counts)

    except (requests.RequestException, ValueError, KeyError):
        # Handle any request or JSON parsing errors
        return


def count_words_in_title(title, word_counts):
    """
    Count occurrences of words in a title.

    Args:
        title (str): The title to search
        word_counts (dict): Dictionary to update with counts
    """
    # Convert title to lowercase for case-insensitive matching
    title_lower = title.lower()

    # Use regex to find whole words only
    # \b ensures word boundaries (no partial matches)
    for word in word_counts.keys():
        # Create pattern to match whole word only
        pattern = r'\b' + re.escape(word) + r'\b'
        matches = re.findall(pattern, title_lower)
        word_counts[word] += len(matches)


def print_results(word_counts):
    """
    Print results sorted by count (descending) then alphabetically.

    Args:
        word_counts (dict): Dictionary of word counts
    """
    filtered_counts = {word: count for word, count in word_counts.items()
                       if count > 0}

    sorted_words = sorted(filtered_counts.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_words:
        print("{}: {}".format(word, count))
