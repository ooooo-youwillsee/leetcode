//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0234_SOLUTION3_H
#define CPP_0234_SOLUTION3_H


#include "ListNode.h"


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *low = head, *fast = head, *prev = nullptr, *temp = nullptr;
        while (fast && fast->next) {
            temp = low;
            low = low->next;
            fast = fast->next->next;
            temp->next = prev;
            prev = temp;
        }

        if (fast && !fast->next) {
            low = low->next;
        }

        while (prev && low) {
            if (prev->val != low->val) return false;
            prev = prev->next;
            low = low->next;
        }
        return true;
    }
};

#endif //CPP_0234_SOLUTION3_H
