//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0024_LISTNODE_H
#define CPP_0024_LISTNODE_H


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

#endif //CPP_0024_LISTNODE_H
