//
// Created by ooooo on 2019/12/2.
//
#ifndef CPP_0208_SOLUTION1_H
#define CPP_0208_SOLUTION1_H

#include <string>
#include <vector>

using namespace std;

class Trie {

private:

    struct Node {
        char c;
        vector<Node *> children = vector<Node *>(26, nullptr);
        bool isWord = false;

        Node(char c) {
            this->c = c;
        }

        Node() {

        }
    };

    Node *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = this->root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (node->children[index]) {
                node = node->children[index];
            } else {
                node->children[index] = new Node(word[i]);
                node = node->children[index];
            }
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = this->root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = this->root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //CPP_0208_SOLUTION1_H
