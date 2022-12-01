#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        elves = ifile.read().split('\n\n')
    cals = sorted(sum(int(c) for c in elf.split()) for elf in elves)

    print(cals[-1]) # 1
    print(sum(cals[-3:])) # 2

if __name__ == '__main__':
    main()
