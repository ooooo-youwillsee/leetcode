//
// Created by ooooo on 2019/10/29.
//
#ifndef CPP_0206_SOLUTION1_H
#define CPP_0206_SOLUTION1_H

#include <iostream>
#include "ListNode.h"

using namespace std;


class Solution1 {

private:



public:
    ListNode *reverseList(ListNode *head) {

        ListNode *prev = NULL;
        while (head) {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

};

#endif //CPP_0206_SOLUTION1_H
