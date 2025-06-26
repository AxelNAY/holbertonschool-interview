# Log Parsing

## Description
This project implements a real-time log parsing system that reads web server log entries from stdin and computes metrics including total file size and HTTP status code counts. The system processes logs in the format commonly used by web servers and provides periodic statistics output.

## Project Structure

```
log_parsing/
├── 0-generator.py    # Log generator for testing
├── 0-stats.py       # Main log parsing script
└── README.md        # This file
```

## Log Format

The expected log format is:
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

Example:
```
127.0.0.1 - [2017-02-05 23:24:34.777044] "GET /projects/260 HTTP/1.1" 200 512
```

## Features

### Main Script (`0-stats.py`)
- **Real-time processing**: Reads log entries from stdin line by line
- **Periodic reporting**: Prints statistics every 10 lines processed
- **Graceful interruption**: Handles Ctrl+C (SIGINT) and prints final stats
- **Error handling**: Skips malformed log entries without crashing
- **Efficient counting**: Uses defaultdict for O(1) status code counting

### Test Generator (`0-generator.py`)
- **Realistic simulation**: Generates random log entries with proper format
- **Random delays**: Simulates real-time log generation with sleep intervals
- **Varied data**: Random IP addresses, timestamps, status codes, and file sizes
- **Large dataset**: Generates 10,000 log entries for comprehensive testing

## Tracked Metrics

### File Size
- **Total cumulative size** of all processed files
- Displayed as: `File size: <total>`

### HTTP Status Codes
Tracks occurrences of the following status codes:
- **200**: OK
- **301**: Moved Permanently  
- **400**: Bad Request
- **401**: Unauthorized
- **403**: Forbidden
- **404**: Not Found
- **405**: Method Not Allowed
- **500**: Internal Server Error

Only valid status codes are counted; invalid codes are ignored.

## Usage

### Basic Usage
```bash
./0-stats.py < logfile.txt
```

### With the Generator
```bash
./0-generator.py | ./0-stats.py
```

### Real-time Monitoring
```bash
tail -f /var/log/apache2/access.log | ./0-stats.py
```

## Output Format

Statistics are printed every 10 lines and on program termination:

```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
```

## Key Features

### Robust Error Handling
- Malformed lines are silently skipped
- IndexError and ValueError exceptions are caught
- Program continues processing despite individual line errors

### Memory Efficient
- Processes logs line by line without storing entire dataset
- Uses defaultdict for efficient status code counting
- Constant memory usage regardless of log size

### Signal Handling
- Graceful shutdown on Ctrl+C (KeyboardInterrupt)
- Final statistics printed before exit
- No data loss on interruption

## Implementation Details

### Data Structures
- `total_size`: Integer accumulator for file sizes
- `status_counts`: defaultdict(int) for status code frequencies
- `valid_status_codes`: Set for O(1) status code validation

### Algorithm
1. Read each line from stdin
2. Split line into components
3. Extract status code and file size from end of line
4. Validate status code against known valid codes
5. Update counters
6. Print statistics every 10 lines
7. Handle interruptions gracefully

## Testing

### Generate Test Data
```bash
./0-generator.py > test_logs.txt
```

### Process Test Data
```bash
./0-stats.py < test_logs.txt
```

### Real-time Testing
```bash
./0-generator.py | ./0-stats.py
```

## Requirements

- Python 3.x
- Standard library modules: `sys`, `collections`, `random`, `time`, `datetime`
- Unix-like environment for proper signal handling

## Error Scenarios Handled

- Malformed log lines (wrong number of fields)
- Non-numeric file sizes
- Invalid status codes
- Empty or incomplete lines
- Keyboard interruption (Ctrl+C)

## Performance

- **Time Complexity**: O(n) where n is the number of log lines
- **Space Complexity**: O(1) constant space usage
- **Throughput**: Can process thousands of log entries per second

## Author

This implementation follows Python best practices and is designed for production log monitoring environments.