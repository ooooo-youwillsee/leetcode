//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_1046_SOLUTION1_H
#define CPP_1046_SOLUTION1_H

#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq(less<int>(), stones);
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(x - y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

#endif //CPP_1046_SOLUTION1_H
