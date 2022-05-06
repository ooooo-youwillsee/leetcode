//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0257_SOLUTION1_H
#define CPP_0257_SOLUTION1_H

#include <vector>
#include <queue>
#include <unordered_map>
#include "TreeNode.h"

class Solution {
public:
    vector<string> binaryTreePaths2(TreeNode *root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};

        queue<TreeNode *> q;
        queue<TreeNode *> prev;
        unordered_map<TreeNode *, string> paths;
        vector<string> res;

        q.push(root);
        prev.push(root);
        paths[root] = to_string(root->val);
        while (!q.empty()) {
            TreeNode *node = q.front();
            TreeNode *parent = prev.front();
            q.pop();
            prev.pop();
            if (node != root) {
                if (!node->left && !node->right) {
                    res.push_back(paths[parent] + "->" + to_string(node->val));
                    continue;
                }
                paths[node] = paths[parent] + "->" + to_string(node->val);
            }
            if (node->left) {
                q.push(node->left);
                prev.push(node);
            }
            if (node->right) {
                q.push(node->right);
                prev.push(node);
            }
        }
        return res;
    }


    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        queue<TreeNode *> q;
        queue<string> paths;
        vector<string> res;
        q.push(root);
        paths.push(to_string(root->val));
        while (!q.empty()) {
            TreeNode *node = q.front();
            string parentPath = paths.front();
            q.pop();
            paths.pop();
            if (node != root) {
                if (!node->left && !node->right) {
                    res.push_back(parentPath + "->" + to_string(node->val));
                    continue;
                }
                parentPath += "->" + to_string(node->val);
            }
            if (node->left) {
                q.push(node->left);
                paths.push(parentPath);
            }
            if (node->right) {
                q.push(node->right);
                paths.push(parentPath);
            }
        }
        return res;
    }
};

#endif //CPP_0257_SOLUTION1_H
