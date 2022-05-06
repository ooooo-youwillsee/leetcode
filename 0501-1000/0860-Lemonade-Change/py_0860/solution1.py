# -*- coding: utf-8 -*-
# @Time    : 2020/12/10 09:08
# @Author  : ooooo


from typing import *


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        bill_5, bill_10 = 0, 0
        for bill in bills:
            if bill == 5:
                bill_5 += 1
            elif bill == 10:
                bill_5 -= 1
                bill_10 += 1
            else:
                if bill_10 <= 0:
                    bill_5 -= 3
                else:
                    bill_5 -= 1
                    bill_10 -= 1
            if bill_5 < 0 or bill_10 < 0:
                return False
        return True
