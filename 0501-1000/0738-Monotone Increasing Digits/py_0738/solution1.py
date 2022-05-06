# -*- coding: utf-8 -*-
# @Time    : 2020/12/18 21:30
# @Author  : ooooo

from typing import *


class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        num_chars = list(str(N))
        flag = len(num_chars)
        for i in range(len(num_chars) - 1, 0, -1):
            if num_chars[i] < num_chars[i - 1]:
                num_chars[i - 1] = chr(ord(num_chars[i - 1]) - 1)
                flag = i
        for i in range(flag, len(num_chars)):
            num_chars[i] = '9'

        return int(''.join(num_chars))


if __name__ == '__main__':
    s = Solution()
    print(s.monotoneIncreasingDigits(1234))
    print(s.monotoneIncreasingDigits(332))
    print(s.monotoneIncreasingDigits(10))
