//
// Created by ooooo on 2020/1/14.
//
#ifndef CPP_0720__SOLUTION3_H_
#define CPP_0720__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Trie
 */
class Solution {
 private:

  struct Node {
    char c;
    bool isWord;
    vector<Node *> children;

    Node(char c) : c(c), children(vector<Node *>(26, nullptr)) {
      isWord = false;
    }

    void insert(string s) {
      Node *curNode = this;
      for (const auto &item: s) {
        int index = item - 'a';
        if (!curNode->children[index]) {
          curNode->children[index] = new Node(item);
        }
        curNode = curNode->children[index];
      }
      curNode->isWord = true;
    }

    bool check(string s) {
      Node *curNode = this;
      for (const auto &item: s) {
        int index = item - 'a';
        Node *node = curNode->children[index];
        if (!node || !node->isWord) return false;
        curNode = node;
      }
      return true;
    }
  };

 public:
  string longestWord(vector<string> &words) {
    Node *root = new Node(0);
    for (const auto &word: words) {
      root->insert(word);
    }
    string ans = "";
    for (const auto &word: words) {
      if (root->check(word) && (ans.size() < word.size() || (ans.size() == word.size() && word < ans))) {
        ans = word;
      }
    }
    return ans;
  }
};

#endif //CPP_0720__SOLUTION3_H_
