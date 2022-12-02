#!/usr/bin/env python
from heapq import heappushpop
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        cals = [0, 0, 0]
        for elf in ifile.read().split('\n\n'):
            heappushpop(cals, sum(int(c) for c in elf.split()))

    print(max(cals)) # 1
    print(sum(cals)) # 2

if __name__ == '__main__':
    main()
