//
// Created by ooooo on 2020/2/7.
//
#ifndef CPP_0211__SOLUTION1_H_
#define CPP_0211__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class WordDictionary {

 private:

  struct Node {
    bool isWord;
    vector<Node *> next;
    Node() : isWord(false), next(26, nullptr) {}
  };

  Node *root;

 public:
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new Node();
  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    add(root, word, 0);
  }

  void add(Node *node, string word, int i) {
    if (i == word.size()) {
      node->isWord = true;
      return;
    }
    char c = word[i];
    if (node->next[c - 'a'] == nullptr) {
      node->next[c - 'a'] = new Node();
    }
    add(node->next[c - 'a'], word, i + 1);
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return search(root, word, 0);
  }

  bool search(Node *node, string &word, int i) {
    if (!node) return false;
    if (i == word.size()) {
      return node->isWord;
    }
    char c = word[i];
    if (c == '.') {
      for (auto &item: node->next) {
        if (search(item, word, i + 1)) return true;
      }
      return false;
    }
    return search(node->next[c - 'a'], word, i + 1);
  }
};

#endif //CPP_0211__SOLUTION1_H_
