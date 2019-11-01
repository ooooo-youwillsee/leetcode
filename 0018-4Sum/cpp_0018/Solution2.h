//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0018_SOLUTION2_H
#define CPP_0018_SOLUTION2_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }

        sort(nums.begin(), nums.end());

        set<vector<int>> set;

        map<int, vector<vector<int>>> m;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int mid = nums[i] + nums[j];
                map<int, vector<vector<int>>>::iterator it = m.find(mid);
                if (it == m.end()) {
                    vector<vector<int>> vec;
                    vector<int> v = {i, j};
                    vec.push_back(v);
                    m[mid] = vec;
                } else {
                    vector<vector<int>> vec = it->second;
                    vector<int> v = {i, j};
                    vec.push_back(v);
                    m[mid] = vec;
                }
            }
        }

        for (auto mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator) {
            int first = mapIterator->first;
            vector<vector<int>> second = mapIterator->second;
            int i = 0;
            int j = nums.size() - 1;
            while (i < j) {
                int n = nums[i] + nums[j] + first;
                if (n < target) {
                    i += 1;
                } else if (n > target) {
                    j -= 1;
                } else {
                    for (auto item : second) {
                        if (item[0] != i && item[0] != j && item[1] != i && item[1] != j) {
                            vector<int> vec = {nums[i], nums[j], nums[item[0]], nums[item[1]]};
                            sort(vec.begin(), vec.end());
                            set.insert(vec);
                        }
                    }
                    i += 1;
                    j -= 1;
                }
            }
        }

        for (auto item: set) {
            res.push_back(item);
        }

        return res;
    }
};

#endif //CPP_0018_SOLUTION2_H
