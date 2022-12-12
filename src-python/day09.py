#!/usr/bin/env python
from aoc import get_input

vdir = {'R': 1, 'D': 1j, 'L': -1, 'U': -1j}

def sign(x):
    return (x > 0) - (x < 0)

def main():
    with get_input(__file__) as ifile:
        rope = [0j] * 10
        rset1 = {0j}
        rset2 = {0j}
        for line in ifile:
            xdir = vdir[line[0]]
            for _ in range(int(line[2:])):
                rope[0] += xdir
                for i in range(1, len(rope)):
                    diff = rope[i-1] - rope[i]
                    if abs(diff.real) > 1 or abs(diff.imag) > 1:
                        rope[i] += sign(diff.real) + sign(diff.imag) * 1j
                        if i == 1:
                            rset1.add(rope[i])
                        elif i == 9:
                            rset2.add(rope[i])

    print(len(rset1)) # 1
    print(len(rset2)) # 2

if __name__ == '__main__':
    main()
