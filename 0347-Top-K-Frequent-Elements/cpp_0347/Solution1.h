//
// Created by ooooo on 2020/1/24.
//
#ifndef CPP_0347__SOLUTION1_H_
#define CPP_0347__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  struct Freq {
    int val;
    int times;
    Freq(int val, int times) : val(val), times(times) {}
    bool operator<(const Freq &x) const { return this->times > x.times; }
  };

  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (auto num: nums)
      m[num]++;

    priority_queue<Freq> pq;
    for (auto entry: m) {
      Freq item(entry.first, entry.second);
      if (pq.size() < k) {
        pq.push(item);
      } else {
        Freq top = pq.top();
        if (item.times > top.times) {
          pq.pop();
          pq.push(item);
        }
      }
    }

    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top().val);
      pq.pop();
    }
    return ans;
  }
};

#endif //CPP_0347__SOLUTION1_H_
