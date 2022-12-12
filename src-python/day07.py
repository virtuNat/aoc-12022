#!/usr/bin/env python
from aoc import get_input

def main():
    dsize = [0]
    stack = []
    index = 0
    with get_input(__file__) as ifile:
        for line in ifile:
            if line[0].isdigit():
                val = int(line.split()[0])
                for idx in stack:
                    dsize[idx] += val
                continue
            if line.startswith('$ cd'):
                if line[-2] == '.':
                    stack.pop()
                    continue
                dsize.append(0)
                stack.append(index)
                index += 1

    print(sum(v for v in dsize if v <= 100000)) # 1
    fspace = dsize[0] - 40000000
    print(min(v for v in dsize if v >= fspace)) # 2

if __name__ == '__main__':
    main()
