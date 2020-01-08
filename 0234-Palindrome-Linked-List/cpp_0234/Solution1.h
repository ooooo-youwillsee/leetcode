//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0234_SOLUTION1_H
#define CPP_0234_SOLUTION1_H

#include "ListNode.h"
#include <vector>

/**
 * 循环
 */
class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> ans;
        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = ans.size() - 1; i < j; ++i, --j) {
            if (ans[i] != ans[j]) return false;
        }
        return true;
    }
};

#endif //CPP_0234_SOLUTION1_H
