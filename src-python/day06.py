#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        buf = ifile.read()
        for i in range(4, len(buf)):
            if len(set(buf[i-4:i])) == 4:
                print(i) # 1
                break
        for i in range(14, len(buf)):
            if len(set(buf[i-14:i])) == 14:
                print(i) # 2
                break

if __name__ == '__main__':
    main()
