#!/usr/bin/env python
from aoc import get_input

def main():
    score = [0, 0]
    lines = []
    with get_input(__file__) as ifile:
        for line in ifile:
            line = line.strip()
            half = len(line) // 2

            item = set(line[:half]).intersection(line[half:])
            item, = item
            score[0] += ord(item) - (96 if item.islower() else 38)

            lines.append(line)
            if len(lines) == 3:
                badge = set(lines[0]).intersection(lines[1]).intersection(lines[2])
                badge, = badge
                score[1] += ord(badge) - (96 if badge.islower() else 38)
                lines.clear()

    print(score[0]) # 1
    print(score[1]) # 2

if __name__ == '__main__':
    main()
