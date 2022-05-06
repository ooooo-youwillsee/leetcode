//
// Created by ooooo on 2020/3/25.
//
#ifndef CPP_041__SOLUTION1_H_
#define CPP_041__SOLUTION1_H_

#include <iostream>
#include <queue>

using namespace std;

/**
 * solution1 : AVL树，每个节点记录子节点个数
 * solution2 : 最大堆 < 最小堆
 */
class MedianFinder {
 private:
  priority_queue<int, vector<int>, less<int>> max;
  priority_queue<int, vector<int>, greater<int>> min;

 public:
  /** initialize your data structure here. */
  MedianFinder() {
  }

  void addNum(int num) {
    if (max.empty()) {
      max.push(num);
      return;
    }

    if (min.size() == max.size()) {
      if (num > min.top()) {
        max.push(min.top());
        min.pop();
        min.push(num);
      } else {
        max.push(num);
      }
    } else {
      if (num >= max.top()) {
        min.push(num);
      } else {
        min.push(max.top());
        max.pop();
        max.push(num);
      }
    }

  }

  double findMedian() {
    if (min.size() == max.size()) {
      return (min.top() + max.top()) / 2.0;
    } else {
      return max.top();
    }
  }
};

#endif //CPP_041__SOLUTION1_H_
