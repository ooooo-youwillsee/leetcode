# -*- coding: utf-8 -*-
# @Time    : 2020/11/22 12:56
# @Author  : ooooo


from typing import *


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m = dict()
        for i in s:
            if i in m:
                m[i] += 1
            else:
                m[i] = 1
        for i in t:
            if i not in m or m[i] == 0:
                return False
            m[i] -= 1
            if m[i] == 0:
                del m[i]
        return len(m) == 0


if __name__ == '__main__':
    s = Solution()
    print(s.isAnagram('anagram', 'nagaram')) # True
    print(s.isAnagram('rat', 'cat')) # False
    print(s.isAnagram('ab', 'a')) # False
