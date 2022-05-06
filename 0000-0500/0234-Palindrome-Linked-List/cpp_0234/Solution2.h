//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0234_SOLUTION2_H
#define CPP_0234_SOLUTION2_H


#include "ListNode.h"

class Solution {
public:

    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *low = head, *fast = head, *prev = nullptr, *temp = nullptr;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            temp = low->next;
            low->next = prev;
            prev = low;
            low = temp;
        }
        ListNode *left = nullptr;
        ListNode *right = low->next;
        if (!fast->next) {
            left = prev;
        } else {
            low->next = prev;
            left = low;
        }
        bool match = true;
        while (match && left && right) {
            if (left->val != right->val) {
                match = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        return match;
    }
};

#endif //CPP_0234_SOLUTION2_H
