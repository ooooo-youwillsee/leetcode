# -*- coding: utf-8 -*-
# @Time    : 2020/12/3 12:14
# @Author  : ooooo

from typing import *
from math import sqrt


class Solution:

    def is_prime(self, n):
        x = int(sqrt(n)) + 1
        if n == 1: return 0
        if n == 2: return 1
        if n % 2 == 0: return 0
        for i in range(3, x, 2):
            if n % i == 0: return 0
        return 1

    def countPrimes(self, n: int) -> int:
        return sum([self.is_prime(x) for x in range(1, n)])
