# -*- coding: utf-8 -*-
# @Time    : 2020/12/30 09:03
# @Author  : ooooo

from typing import *
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-x for x in stones]
        heapq.heapify(pq)
        while len(pq) > 1:
            a, b = heapq.heappop(pq), heapq.heappop(pq)
            if a != b:
                heapq.heappush(pq, a - b)
        return -pq[0] if pq else 0
