//
// Created by ooooo on 2020/2/12.
//
#ifndef CPP_0056__SOLUTION1_H_
#define CPP_0056__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * 合并 => [1, n-1]
 */
class Solution {
 public:

  struct Range {
    int start, end;
    Range(int start, int an_end) : start(start), end(an_end) {}
    Range() {}
    bool operator<(const Range &other) const {
      return this->start < other.start;
    }
  };

  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) return intervals;
    vector<Range> vec;
    for (int i = 0; i < intervals.size(); ++i) {
      auto item = intervals[i];
      vec.push_back(Range(item[0], item[1]));
    }
    sort(vec.begin(), vec.end());
    vector<vector<int>> ans;

    Range item = vec[0];
    for (int i = 1; i < vec.size(); i++) {
      if (item.end >= vec[i].start) {
        item = Range(item.start, max(item.end, vec[i].end));
      } else {
        ans.push_back({item.start, item.end});
        item = vec[i];
      }
      if (i == vec.size() - 1) {
        ans.push_back({item.start, item.end});
      }
    }

    return ans;
  }
};

#endif //CPP_0056__SOLUTION1_H_
