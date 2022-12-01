#!/usr/bin/env python
from math import prod
from itertools import count, starmap
from aoc import get_input

def treecount(trees, dx, dy):
    width = len(trees[0])
    return sum(
        trees[y][x % width] == '#'
        for x, y in zip(count(0, dx), range(0, len(trees), dy))
        )

def main():
    with get_input(__file__) as ifile:
        trees = [line[:-1] for line in ifile]
    
    print(treecount(trees, 3, 1)) # 1
    print(prod(starmap(
        treecount,
        ((trees, 1, 1), (trees, 3, 1), (trees, 5, 1), (trees, 7, 1), (trees, 1, 2))
        ))) # 2

if __name__ == '__main__':
    main()
