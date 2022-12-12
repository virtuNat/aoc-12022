#!/usr/bin/env python
import numpy as np
# import matplotlib.pyplot as plt
from aoc import get_input, get_fname

def main():
    with get_input(__file__) as ifile:
        trees = np.memmap(get_fname(__file__), dtype='uint8', mode='r')
        trees = trees[trees >= 48].reshape(-1, np.nonzero(trees < 48)[0][0]) - 48

    core = trees[1:-1,1:-1]
    visible = core > np.maximum.accumulate(trees[:,1:-1])[:-2]
    visible |= core > np.maximum.accumulate(trees[::-1,1:-1])[-3::-1]
    visible |= core > np.maximum.accumulate(trees[1:-1,:], axis=1)[:,:-2]
    visible |= core > np.maximum.accumulate(trees[1:-1,::-1], axis=1)[:,-3::-1]

    print(np.count_nonzero(visible) + sum(trees.shape)*2 - 4) # 1
    # plt.imshow(visible)
    # plt.show()

    # scene = 0
    # for y in range(len(trees)):
    #     for x in range(len(trees[0])):
    #         c = trees[y][x]
    #         du = dl = dd = dr = 0
    #         for j in range(y-1, -1, -1):
    #             if trees[j][x] >= c:
    #                 du += 1
    #                 break
    #             du += 1
    #         for i in range(x-1, -1, -1):
    #             if trees[y][i] >= c:
    #                 dl += 1
    #                 break
    #             dl += 1
    #         for j in range(y+1, len(trees)):
    #             if trees[j][x] >= c:
    #                 dd += 1
    #                 break
    #             dd += 1
    #         for i in range(x+1, len(trees[0])):
    #             if trees[y][i] >= c:
    #                 dr += 1
    #                 break
    #             dr += 1
    #         scene = max(scene, du * dl * dd * dr)
    # print(scene) # 2

if __name__ == '__main__':
    main()
