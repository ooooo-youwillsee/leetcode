//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0703_SOLUTION1_H
#define CPP_0703_SOLUTION1_H

#include <iostream>
#include <queue>

using namespace std;

class KthLargest {

private:

    priority_queue<int, vector<int>, greater<int>> q;
    int k;

public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto item : nums) {
            add(item);
        }
    }

    int add(int val) {
        if (q.size() < k) {
            q.push(val);
        } else if (q.top() < val) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};


#endif //CPP_0703_SOLUTION1_H
