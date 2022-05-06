//
// Created by ooooo on 2020/2/2.
//
#ifndef CPP_0307__SOLUTION1_H_
#define CPP_0307__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class NumArray {

 private:
  template<typename T>
  struct SegmentTree {
    vector<T> tree, data;
    SegmentTree(vector<T> data) : data(data.size()), tree(data.size() * 4) {
      for (int i = 0; i < data.size(); ++i) {
        this->data[i] = data[i];
      }
      if (!data.empty()) {
        buildSegmentTree(0, 0, data.size() - 1);
      }
    }

    void buildSegmentTree(int treeIndex, int left, int right) {
      if (left == right) {
        this->tree[treeIndex] = this->data[left];
        return;
      }
      int mid = left + (right - left) / 2;
      buildSegmentTree(leftChild(treeIndex), left, mid);
      buildSegmentTree(rightChild(treeIndex), mid + 1, right);
      tree[treeIndex] = merge(tree[leftChild(treeIndex)], tree[rightChild(treeIndex)]);
    }

    T query(int queryL, int queryR) {
      return query(0, 0, data.size() - 1, queryL, queryR);
    }

    T query(int treeIndex, int left, int right, int queryL, int queryR) {
      if (queryL == left && queryR == right) {
        return tree[treeIndex];
      }
      int mid = left + (right - left) / 2;
      if (queryL > mid) {
        return query(rightChild(treeIndex), mid + 1, right, queryL, queryR);
      } else if (queryR <= mid) {
        return query(leftChild(treeIndex), left, mid, queryL, queryR);
      }
      T leftResult = query(leftChild(treeIndex), left, mid, queryL, mid);
      T rightResult = query(rightChild(treeIndex), mid + 1, right, mid + 1, queryR);
      return merge(leftResult, rightResult);
    }

    void set(int i, T v) {
      this->data[i] = v;
      set(0, 0, data.size() - 1, i);
    }

    void set(int treeIndex, int left, int right, int targetIndex) {
      if (left == right) {
        tree[treeIndex] = data[left];
        return;
      }
      int mid = left + (right - left) / 2;
      if (targetIndex > mid) {
        set(rightChild(treeIndex), mid + 1, right, targetIndex);
      } else if (targetIndex <= mid) {
        set(leftChild(treeIndex), left, mid, targetIndex);
      }
      tree[treeIndex] = merge(tree[leftChild(treeIndex)], tree[rightChild(treeIndex)]);
    }

    int leftChild(int i) {
      return 2 * i + 1;
    }
    int rightChild(int i) {
      return 2 * i + 2;
    }
    T merge(T a, T b) {
      return a + b;
    }
  };

  SegmentTree<int> segmentTree;
  int size;

 public:

  NumArray(vector<int> &nums) : segmentTree(nums) {
  }
  void update(int i, int val) {
    segmentTree.set(i, val);
  }

  int sumRange(int i, int j) {
    return segmentTree.query(i, j);
  }
};

#endif //CPP_0307__SOLUTION1_H_
