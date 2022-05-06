//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0239_SOLUTION1_H
#define CPP_0239_SOLUTION1_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        if (nums.size() < k) {
            return res;
        }

        deque<int> q;
        for (int i = 0, len = nums.size(); i < len; ++i) {
            if (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};

#endif //CPP_0239_SOLUTION1_H
