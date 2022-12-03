#!/usr/bin/env python
from aoc import get_input

def main():
    with get_input(__file__) as ifile:
        score = [0, 0]
        lines = []
        for line in ifile:
            line = line.strip()
            half = len(line) // 2

            item = set(line[:half]) & set(line[half:])
            item, = item
            score[0] += ord(item) + (1 - ord('a') if item.islower() else 27 - ord('A'))

            lines.append(set(line))
            if len(lines) == 3:
                badge = lines[0] & lines[1] & lines[2]
                badge, = badge
                score[1] += ord(badge) + (1 - ord('a') if badge.islower() else 27 - ord('A'))
                lines.clear()

    print(score[0]) # 1
    print(score[1]) # 2

if __name__ == '__main__':
    main()
