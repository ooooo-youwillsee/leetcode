# -*- coding: utf-8 -*-
# @Time    : 2020/12/19 18:51
# @Author  : ooooo

from typing import *


class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern): return False
        p2word, word2p = {}, {}
        for i in range(len(pattern)):
            p, word = pattern[i], words[i]
            if p in p2word and p2word[p] != word:
                return False
            if word in word2p and word2p[word] != p:
                return False
            p2word[p], word2p[word] = words[i], p
        return True
