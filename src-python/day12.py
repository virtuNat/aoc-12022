#!/usr/bin/env python
from heapq import heappush, heappop
import numpy as np
import matplotlib.pyplot as plt
from aoc import get_input, get_fname

adjacents = ((0, -1), (-1, 0), (1, 0), (0, 1))

def pathfind(graph, goal, start=None): # A*
    nodes = [(0, goal)]
    gcost = {goal: 0}
    while nodes:
        _, cnode = heappop(nodes)
        if cnode[1] == 0 and (start is None or cnode[0] == start[0]):
            return gcost[cnode]
        for dy, dx in adjacents:
            nnode = (cnode[0] + dy, cnode[1] + dx)
            try:
                if graph[cnode] - graph[nnode] > 1:
                    continue
            except IndexError:
                continue
            ncost = gcost[cnode] + 1
            if gcost.get(nnode, float('inf')) > ncost:
                heappush(nodes, (ncost + nnode[1], nnode))
                gcost[nnode] = ncost
    return float('inf')

def main():
    with get_input(__file__) as ifile:
        graph = []
        start = goal = None
        for line in ifile:
            if start is None and (idx := line.find('S')) > -1:
                start = (len(graph), idx)
                line = f'{line[:idx]}a{line[idx+1:]}'
            if goal is None and (idx := line.find('E')) > -1:
                goal = (len(graph), idx)
                line = f'{line[:idx]}z{line[idx+1:]}'
            graph.append([ord(c) - 97 for c in line.strip()])
        graph = np.array(graph)
    
    print(pathfind(graph, goal, start)) # 1
    print(pathfind(graph, goal)) # 2

    # plt.imshow(graph)
    # plt.show()

if __name__ == '__main__':
    main()
