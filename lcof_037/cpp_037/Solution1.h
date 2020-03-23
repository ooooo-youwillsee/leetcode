//
// Created by ooooo on 2020/3/23.
//
#ifndef CPP_037__SOLUTION1_H_
#define CPP_037__SOLUTION1_H_

#include "TreeNode.h"
#include <queue>
#include <sstream>

class Codec {
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return "[]";
    stringstream ss;
    ss << "[";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      // 判断一层元素是否全为 null
      int c = 0, len = q.size();
      stringstream level_ss;
      for (int i = 0; i < len; ++i) {
        auto node = q.front();
        q.pop();
        if (!node) {
          c++;
          level_ss << "null,";
        } else {
          level_ss << node->val << ",";
          q.push(node->left);
          q.push(node->right);
        }
      }
      if (c != len) ss << level_ss.str();
    }
    auto ans = ss.str();
    ans[ans.size() - 1] = ']';
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    auto nums = splitData(data);
    if (nums.empty()) return nullptr;
    auto root = new TreeNode(stoi(nums[0]));
    queue<TreeNode *> q;
    q.push(root);
    for (int i = 1, len = nums.size(); i < len; i += 2) {
      auto node = q.front();
      q.pop();
      if (nums[i] != "null") node->left = new TreeNode(stoi(nums[i]));
      if (i + 1 >= len) break;
      if (nums[i + 1] != "null") node->right = new TreeNode(stoi(nums[i + 1]));
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    return root;
  }

  vector<string> splitData(string &data) {
    if (data == "[]") return {};
    vector<string> ans;
    int i = 1;
    auto pos = data.find(",", i);
    while (pos != -1) {
      ans.emplace_back(data.substr(i, pos - i));
      i = pos + 1;
      pos = data.find(",", i);
    }
    ans.emplace_back(data.substr(i, data.size() - 1 - i));
    return ans;
  }
};

#endif //CPP_037__SOLUTION1_H_
