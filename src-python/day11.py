#!/usr/bin/env python
import operator as op
from functools import partial
import numpy as np
from aoc import get_input

ops = {'+': op.add, '*': op.mul}

def business(items, monkeys, worry):
    counts = [0] * len(monkeys)
    for _ in range(20 if not worry else 10000):
        for i, (ofunc, divno, tval, fval) in enumerate(monkeys):
            counts[i] += len(items[i])
            for item in items[i]:
                val = ofunc(item) % worry if worry else ofunc(item) // 3
                items[fval if val % divno else tval].append(val)
            items[i] = []
    counts = sorted(counts)
    return counts[-1] * counts[-2]

def main():
    with get_input(__file__) as ifile:
        monkeys = []
        items = []
        while ifile.readline():
            monkey = []
            items.append([int(w) for w in ifile.readline()[18:].split(', ')])
            args = ifile.readline()[23:-1]
            monkey.append(
                (lambda x: x * x)
                if args[2] == 'o' 
                else partial(ops[args[0]], int(args[2:]))
                )
            monkey.append(int(ifile.readline().split()[-1]))
            monkey.append(int(ifile.readline().split()[-1]))
            monkey.append(int(ifile.readline().split()[-1]))
            monkeys.append(monkey)
            ifile.readline()
    
    print(business([i[:] for i in items], monkeys, False)) # 1
    divisor = 1
    for _, divno, *_ in monkeys:
        divisor *= divno
    print(business(items, monkeys, divisor)) # 2

if __name__ == '__main__':
    main()
