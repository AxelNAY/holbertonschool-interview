# Reddit Hot Posts Word Counter

## Description

This project implements a recursive Python function that queries the Reddit API to count keyword occurrences in the titles of hot posts from a specified subreddit. The function handles API pagination, performs case-insensitive word matching, and displays results sorted by frequency.

## Features

- **Recursive API Pagination**: Automatically fetches all pages of hot posts using Reddit's `after` parameter
- **Case-Insensitive Matching**: Converts all text to lowercase for consistent matching
- **Word Boundary Detection**: Uses regex to match whole words only (prevents partial matches)
- **Sorted Results**: Displays counts sorted by frequency (descending), then alphabetically
- **Error Handling**: Gracefully handles invalid subreddits, network errors, and API issues
- **Custom User-Agent**: Uses a proper User-Agent header to comply with Reddit API guidelines

## Requirements

- Python 3.x
- `requests` library

## Installation
```bash
pip install requests
```

## Files

| File | Description |
|------|-------------|
| `0-count.py` | Main implementation with recursive word counting function |
| `0-main.py` | Test/execution script for command-line usage |
| `README.md` | Project documentation |

## Function Prototypes
```python
def count_words(subreddit, word_list, word_counts=None, after=None)
```

### Parameters

- `subreddit` (str): The name of the subreddit to query
- `word_list` (list): List of keywords to count (case-insensitive)
- `word_counts` (dict, optional): Dictionary to accumulate counts across recursive calls
- `after` (str, optional): Reddit API pagination token for fetching next page

### Behavior

- Prints results only when all pages have been processed
- Returns `None` silently if the subreddit is invalid or an error occurs
- Ignores words with 0 occurrences in the output

## Usage

### Command Line
```bash
./0-main.py <subreddit> '<space-separated keywords>'
```

### Examples
```bash
# Count Python-related keywords in programming subreddit
./0-main.py programming 'python java javascript'

# Count gaming terms
./0-main.py gaming 'steam xbox playstation'

# Single keyword
./0-main.py technology 'ai'
```

### Programmatic Usage
```python
from count import count_words

# Count occurrences
count_words('programming', ['python', 'java', 'c++'])
```

## Expected Output Format
```
python: 42
java: 28
javascript: 15
```

Results are printed in the following order:
1. **Primary sort**: By count (highest to lowest)
2. **Secondary sort**: Alphabetically (a-z) for words with equal counts

## How It Works

1. **Initialization**: 
   - Creates a `word_counts` dictionary on first call
   - Normalizes all keywords to lowercase

2. **API Request**:
   - Queries `https://www.reddit.com/r/{subreddit}/hot.json`
   - Uses custom User-Agent header
   - Requests 100 posts per page (maximum allowed)
   - Includes `after` parameter for pagination

3. **Word Counting**:
   - Converts each post title to lowercase
   - Uses regex pattern `\b{word}\b` to match whole words only
   - Counts all occurrences in each title

4. **Pagination**:
   - Checks for `after` token in API response
   - Recursively calls itself with new `after` value
   - Continues until no more pages exist

5. **Output**:
   - Filters out words with 0 occurrences
   - Sorts by count (descending), then alphabetically
   - Prints results only after processing all pages

## Error Handling

The function silently returns (prints nothing) in these cases:

- **Invalid subreddit**: Returns when status code is not 200
- **Redirect (302)**: Handles Reddit redirects for invalid subreddits
- **Network errors**: Catches `requests.RequestException`
- **JSON parsing errors**: Catches `ValueError` and `KeyError`
- **Timeout**: Sets 10-second timeout for requests

## API Details

- **Endpoint**: `https://www.reddit.com/r/{subreddit}/hot.json`
- **Rate Limiting**: Reddit API has rate limits; the script includes a User-Agent
- **Parameters**:
  - `limit`: 100 (maximum posts per request)
  - `after`: Pagination token for next page
- **Authentication**: Not required for public subreddits

## Implementation Notes

### Word Matching
```python
pattern = r'\b' + re.escape(word) + r'\b'
```

- `\b`: Word boundary ensures whole word matching
- `re.escape()`: Escapes special regex characters in keywords
- Case-insensitive via `.lower()` conversion

### Duplicate Keywords

If the same keyword appears multiple times in `word_list` (even with different cases), it's counted once:
```python
word_list = ['Python', 'python', 'PYTHON']  # Treated as single keyword 'python'
```

### Result Sorting
```python
sorted(filtered_counts.items(), key=lambda x: (-x[1], x[0]))
```

- `-x[1]`: Negative count for descending order
- `x[0]`: Word for alphabetical order (ascending)

## Limitations

- Only processes **hot** posts (not new, top, or rising)
- Maximum 100 posts per API request (Reddit limit)
- Does not handle Reddit API authentication (OAuth)
- No rate limiting implementation (may hit Reddit's limits with frequent requests)

## Example Session
```bash
$ ./0-main.py programming 'python java javascript ruby go rust'
python: 126
java: 89
javascript: 72
rust: 43
go: 37
ruby: 21
```
