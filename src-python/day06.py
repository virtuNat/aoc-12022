#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        buf = ifile.read()
    i = 4
    for marklen in 4, 14:
        while len(set(buf[i-marklen:i])) < marklen: 
            i += 1
        print(i) # 1, 2

if __name__ == '__main__':
    main()
