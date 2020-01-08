//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0234_LISTNODE_H
#define CPP_0234_LISTNODE_H

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(vector<int> vec) {
        if (vec.empty()) return;
        this->val = vec[0];
        this->next = nullptr;
        ListNode *head = this;
        for (int i = 1; i < vec.size(); ++i) {
            head->next = new ListNode(vec[i]);
            head = head->next;
        }
    }
};

#endif //CPP_0234_LISTNODE_H
