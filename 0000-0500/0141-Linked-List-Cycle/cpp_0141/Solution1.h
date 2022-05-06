//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0141_SOLUTION1_H
#define CPP_0141_SOLUTION1_H

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        ListNode *low = head;
        ListNode *fast = head->next;

        while (low && fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
            if (low == fast) {
                return true;
            }
        }
        return false;
    }
};

#endif //CPP_0141_SOLUTION1_H
