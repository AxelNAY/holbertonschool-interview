#!/usr/bin/python3
"""
Script that reads logs from standard input (stdin)
and displays statistics:
- Total file size
- Number of lines per valid HTTP status code
Statistics are printed every 10 lines or upon keyboard interruption (CTRL+C).
"""


import sys
import re
from collections import defaultdict


total_size = 0
status_counts = defaultdict(int)
line_count = 0

valid_status_codes = {'200', '301', '400', '401', '403', '404', '405', '500'}

log_pattern = re.compile(
    r'^(\S+) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
)


def print_stats():
    print("File size: {}".format(total_size))
    for code in sorted(valid_status_codes):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")


try:
    for line in sys.stdin:
        line = line.strip()
        match = log_pattern.match(line)
        if match:
            status_code = match.group(3)
            file_size = match.group(4)
            try:
                total_size += int(file_size)
                if status_code in valid_status_codes:
                    status_counts[status_code] += 1
            except ValueError:
                pass
        line_count += 1
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise
