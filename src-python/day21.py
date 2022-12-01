#!/usr/bin/env python
import re
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        foods = []
        for line in ifile:
            i, a = re.match(r'(.+)\(contains (.+)\)', line).groups()
            foods.append((set(i.split()), set(a.split(', '))))
        agens = set.union(*(a for _, a in foods))

    adict = {}
    while len(adict) < len(agens):
        for agent in agens - adict.keys():
            fs = set.intersection(*(i for i, a in foods if agent in a)) - adict.keys()
            if len(fs) == 1:
                adict[next(iter(fs))] = agent
                break
    print(sum(len(i - adict.keys()) for i, _ in foods)) # 1
    print(','.join(sorted(adict, key=adict.__getitem__))) # 2

if __name__ == '__main__':
    main()
