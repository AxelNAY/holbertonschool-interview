#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""

import sys
from collections import defaultdict

if __name__ == "__main__":
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    valid_status_codes = {'200', '301', '400', '401',
                          '403', '404', '405', '500'}

    def print_stats(total_size, status_counts):
        print("File size: {}".format(total_size))
        for code in sorted(valid_status_codes):
            if status_counts[code] > 0:
                print(f"{code}: {status_counts[code]}")

    try:
        for line in sys.stdin:
            line = line.split()
            try:
                status_code = line[-2]
                if status_code in valid_status_codes:
                    status_counts[status_code] += 1
                file_size = line[-1]
                total_size += int(file_size)
            except Exception:
                pass

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
    print_stats(total_size, status_counts)
