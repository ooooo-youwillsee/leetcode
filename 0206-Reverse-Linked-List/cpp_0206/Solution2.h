//
// Created by ooooo on 2019/10/29.
//
#ifndef CPP_0206_SOLUTION2_H
#define CPP_0206_SOLUTION2_H

#include <iostream>
#include "ListNode.h"


using namespace std;

class Solution2 {

public:
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *pNode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return pNode;
    }

};

#endif //CPP_0206_SOLUTION2_H
