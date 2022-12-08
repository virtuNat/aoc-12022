#!/usr/bin/env python
from aoc import get_input

def main():
    count = [0, 0]
    with get_input(__file__) as ifile:
        for line in ifile:
            s1, s2 = line.split(',')
            a1, b1 = map(int, s1.split('-'))
            a2, b2 = map(int, s2.split('-'))
            if a1 <= b2 and b1 >= a2:
                count[1] += 1
                if (a1 <= a2 and b2 <= b1) or (a2 <= a1 and b1 <= b2):
                    count[0] += 1

    print(count[0]) # 1
    print(count[1]) # 2

if __name__ == '__main__':
    main()
