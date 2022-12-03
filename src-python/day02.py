#!/usr/bin/env python
from aoc import get_input

strat1 = {
    'A X': 4, 'A Y': 8, 'A Z': 3,
    'B X': 1, 'B Y': 5, 'B Z': 9,
    'C X': 7, 'C Y': 2, 'C Z': 6,
    }
strat2 = {
    'A X': 3, 'A Y': 4, 'A Z': 8,
    'B X': 1, 'B Y': 5, 'B Z': 9,
    'C X': 2, 'C Y': 6, 'C Z': 7,
    }

def main():
    with get_input(__file__) as ifile:
        score = [0, 0]
        for line in ifile:
            line = line.strip()
            score[0] += strat1[line]
            score[1] += strat2[line]

    print(score[0]) # 1
    print(score[1]) # 2

if __name__ == '__main__':
    main()
