//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0599_NODE_H
#define CPP_0599_NODE_H

#include <istream>
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

#endif //CPP_0599_NODE_H
