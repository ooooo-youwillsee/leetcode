//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0669_TREENODE_H
#define CPP_0669_TREENODE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(vector<int> nums) {
        this->val = nums[0];
        this->left = this->right = nullptr;
        queue<TreeNode *> q;
        q.push(this);
        for (int i = 1; i < nums.size();) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                i += 2;
                continue;
            }
            int leftNum = nums[i++];
            if (leftNum != INT_MIN) {
                node->left = new TreeNode(leftNum);
            }
            int rightNum = nums[i++];
            if (rightNum != INT_MIN) {
                node->right = new TreeNode(rightNum);
            }
            q.push(node->left);
            q.push(node->right);
        }
    }

    void inOrder() {
        inOrder(this);
        cout << endl;
    }

    void inOrder(TreeNode *node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }
};

#endif //CPP_0669_TREENODE_H
