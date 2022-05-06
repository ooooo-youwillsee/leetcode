# -*- coding: utf-8 -*-
# @Time    : 2020/12/14 12:03
# @Author  : ooooo

from typing import *


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        letters = [(i, ''.join(sorted(s))) for i, s in enumerate(strs)]
        letters = sorted(letters, key=lambda a: a[1])
        ans = []
        for i in range(len(letters)):
            j, s = letters[i]
            if i > 0 and letters[i][1] == letters[i - 1][1]:
                ans[-1].append(strs[j])
            else:
                ans.append([strs[j]])
        return ans


if __name__ == '__main__':
    s = Solution()
    ans = s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    print(ans)
