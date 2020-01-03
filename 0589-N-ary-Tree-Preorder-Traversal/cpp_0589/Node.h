//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0589_NODE_H
#define CPP_0589_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

#endif //CPP_0589_NODE_H
