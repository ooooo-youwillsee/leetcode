# -*- coding: utf-8 -*-
# @Time    : 2020/10/17 18:48
# @Author  : ooooo


from typing import *


class Solution:
    left_visited, right_visited, col_visited = set(), set(), set()

    def visited(self, row, col):
        return col in self.col_visited or row - col in self.right_visited or row + col in self.left_visited

    def dfs(self, row):
        if row >= self.n:
            self.count += 1
            return
        for col in range(0, self.n):
            if self.visited(row, col):
                continue
            self.col_visited.add(col)
            self.right_visited.add(row - col)
            self.left_visited.add(row + col)
            self.dfs(row + 1)
            self.col_visited.remove(col)
            self.right_visited.remove(row - col)
            self.left_visited.remove(row + col)

    def totalNQueens(self, n: int) -> int:
        self.count, self.n = 0, n
        self.dfs(0)
        return self.count


if __name__ == '__main__':
    s = Solution()
    print(s.totalNQueens(4))
