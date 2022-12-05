#!/usr/bin/env python
import re
from aoc import get_input

def main():
    regex = re.compile(r'move (\d+) from (\d+) to (\d+)')
    with get_input(__file__) as ifile:
        boxes, proc = ifile.read().split('\n\n')
        boxes = boxes.split('\n')[::-1]
        proc = proc.split('\n')
    stack1 = [[] for _ in boxes[0].split()]
    for row in boxes[1:]:
        for i, q in enumerate(stack1):
            c = row[i*4 + 1]
            if c != ' ':
                q.append(c)
    stack2 = [q.copy() for q in stack1]
    for inst in proc:
        count, i, j = map(int, re.match(regex, inst).groups())
        stack1[j - 1].extend(stack1[i - 1].pop() for _ in range(count))
        stack2[j - 1].extend(stack2[i - 1][-count:])
        del stack2[i - 1][-count:]

    print(''.join(q[-1] for q in stack1)) # 1
    print(''.join(q[-1] for q in stack2)) # 2

if __name__ == '__main__':
    main()
