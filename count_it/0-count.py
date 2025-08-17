#!/usr/bin/python3
"""
Recursive function to count words in Reddit hot posts
"""
import re
import requests


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
    if word_counts is None:
        word_counts = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower in word_counts:
                word_counts[word_lower] = 0
            else:
                word_counts[word_lower] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    headers = {
        'User-Agent': 'python:word_counter:v1.0 (by /u/student)'
    }

    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False, timeout=10)

        if response.status_code == 302:
            return

        if response.status_code != 200:
            return

        data = response.json()

        if 'data' not in data or 'children' not in data['data']:
            return

        posts = data['data']['children']

        if not posts:
            if after is None or len(posts) == 0:
                print_results(word_counts)
            return

        for post in posts:
            if 'data' in post and 'title' in post['data']:
                title = post['data']['title']
                count_words_in_title(title, word_counts)

        next_after = data['data'].get('after')

        if next_after:
            count_words(subreddit, word_list, word_counts, next_after)
        else:
            print_results(word_counts)

    except (requests.RequestException, ValueError, KeyError):
        return


def count_words_in_title(title, word_counts):
    """
    Count occurrences of words in a title.

    Args:
        title (str): The title to search
        word_counts (dict): Dictionary to update with counts
    """
    title_lower = title.lower()

    for word in word_counts.keys():
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
