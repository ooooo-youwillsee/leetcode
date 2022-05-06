//
// Created by ooooo on 2020/1/29.
//
#ifndef CPP_0303__SOLUTION2_H_
#define CPP_0303__SOLUTION2_H_

#include <iostream>
#include <vector>


/**
 * 线段树
 */
using namespace std;

class NumArray {

 private:
  int *tree;
  int *data;
  int size;

 public:
  NumArray(vector<int> &nums) {
    data = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
      data[i] = nums[i];
    }
    size = nums.size();
    tree = new int[nums.size() * 4];
    buildSegmentTree(0, 0, size - 1);
  }

  void buildSegmentTree(int treeIndex, int left, int right) {
    if (left == right) {
      tree[treeIndex] = data[left];
      return;
    }
    int mid = left + (right - left) / 2;
    buildSegmentTree(leftChild(treeIndex), left, mid);
    buildSegmentTree(rightChild(treeIndex), mid + 1, right);
    tree[treeIndex] = merge(tree[leftChild(treeIndex)], tree[rightChild(treeIndex)]);
  }

  int merge(int a, int b) {
    return a + b;
  }

  int leftChild(int i) {
    return 2 * i + 1;
  }

  int rightChild(int i) {
    return 2 * i + 2;
  }

  int sumRange(int i, int j) {
    return sumRange(0, 0, size - 1, i, j);
  }

  int sumRange(int treeIndex, int left, int right, int queryLeft, int queryRight) {
    if (queryLeft == left && queryRight == right) {
      return tree[treeIndex];
    }
    int mid = left + (right - left) / 2;
    if (queryLeft > mid) {
      return sumRange(rightChild(treeIndex), mid + 1, right, queryLeft, queryRight);
    } else if (queryRight <= mid) {
      return sumRange(leftChild(treeIndex), left, mid, queryLeft, queryRight);
    }
    int leftValue = sumRange(leftChild(treeIndex), left, mid, queryLeft, mid);
    int rightValue = sumRange(rightChild(treeIndex), mid + 1, right, mid + 1, queryRight);
    return merge(leftValue, rightValue);
  }
};

#endif //CPP_0303__SOLUTION2_H_
