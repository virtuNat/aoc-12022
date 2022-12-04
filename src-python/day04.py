#!/usr/bin/env python
import re
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        count = [0, 0]
        for line in ifile:
            a, b, c, d = map(int, re.findall(r'\d+', line))
            if (a <= c and d <= b) or (c <= a and b <= d):
                count[0] += 1
            if a <= d and b >= c:
                count[1] += 1

    print(count[0]) # 1
    print(count[1]) # 2

if __name__ == '__main__':
    main()
