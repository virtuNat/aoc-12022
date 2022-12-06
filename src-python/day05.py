#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        boxes, proc = ifile.read().split('\n\n')
        boxes = boxes.split('\n')[::-1]
        proc = proc.split('\n')
    stack1 = [[] for _ in boxes[0].split()]
    stack2 = [q.copy() for q in stack1]
    for row in boxes[1:]:
        for i, c in enumerate(row[1::4]):
            if c != ' ':
                stack1[i].append(c)
                stack2[i].append(c)
    for inst in proc:
        count = int(inst[5:7])
        i = int(inst[-6]) - 1
        j = int(inst[-1]) - 1
        stack1[j].extend(stack1[i].pop() for _ in range(count))
        stack2[j].extend(stack2[i][-count:])
        del stack2[i][-count:]

    print(''.join(q[-1] for q in stack1)) # 1
    print(''.join(q[-1] for q in stack2)) # 2

if __name__ == '__main__':
    main()
