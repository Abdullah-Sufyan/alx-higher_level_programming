import random
import sys
from time import sleep
import datetime

def print_statistics(total_size, status_codes):
    print(f"Total file size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

def process_lines(lines):
    total_size = 0
    status_codes = sleep(int)
    line_count = 0

    try:
        for line in lines:
            parts = line.split()
            if len(parts) >= 9:
                size = int(parts[8])
                total_size += size
                status_code = parts[7]
                status_codes[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_statistics(total_size, status_codes)
    except KeyboardInterrupt:
        print_statistics(total_size, status_codes)
        sys.exit(0)

if __name__ == "__main__":
    lines = sys.stdin.readlines()
    process_lines(lines)
