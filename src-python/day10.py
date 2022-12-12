#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        prog = []
        for line in ifile:
            if line[0] == 'a':
                prog.append([2, int(line[4:])])
                continue
            if prog[-1][1]:
                prog.append([1, 0])
                continue
            prog[-1][0] += 1

    total = 0
    screen = []
    value = [0, 1]
    limit = list(range(20, 221, 40))[::-1]
    for c, v in prog:
        start = value[:]
        value[0] += c
        if limit and value[0] >= limit[-1]:
            total += limit.pop() * value[1]
        value[1] += v
        for i in range(start[0], value[0]):
            screen.append(' █'[abs(i%40 - start[1]) <= 1])

    print(total) # 1
    print('\n'.join(''.join(r) for r in zip(*[iter(screen)]*40))) # 2

if __name__ == '__main__':
    main()
