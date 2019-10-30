//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0024_SOLUTION1_H
#define CPP_0024_SOLUTION1_H

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {

public:

    /**
     * 给定 1->2->3->4, 你应该返回 2->1->4->3.
     * @param head
     * @return
     */
    ListNode *swapPairs(ListNode *head) {
        ListNode *result = head;
        ListNode *cur = head;
        ListNode *prev = NULL;
        while (cur && cur->next) {
            ListNode *a = cur;
            ListNode *b = cur->next;
            if (!prev) {
                result = b;
            }
            cur = b->next;
            b->next = a;
            prev = a;
            prev->next = cur ? cur->next ? cur->next : cur : NULL;
        }

        return result;
    }
};

#endif //CPP_0024_SOLUTION1_H
