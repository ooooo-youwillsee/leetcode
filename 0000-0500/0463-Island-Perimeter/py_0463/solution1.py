# -*- coding: utf-8 -*-
# @Time    : 2020/10/30 09:06
# @Author  : ooooo


from typing import *


class Solution:

    def inArea(self, i, j):
        if i >= len(self.grid) or i < 0 or j >= len(self.grid[0]) or j < 0:
            return 0
        return self.grid[i][j] == 1

    def surround(self, i, j):
        return 4 - (self.inArea(i + 1, j) + self.inArea(i - 1, j) + self.inArea(i, j - 1) + self.inArea(i, j + 1))

    def islandPerimeter(self, grid: List[List[int]]) -> int:
        if len(grid) == 0:
            return 0
        self.grid = grid
        sum = 0
        for i, row in enumerate(grid):
            for j, item in enumerate(row):
                if grid[i][j] == 1:
                    sum += self.surround(i, j)
        return sum
