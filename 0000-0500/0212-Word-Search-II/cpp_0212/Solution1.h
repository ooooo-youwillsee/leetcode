//
// Created by ooooo on 2019/12/4.
//
#ifndef CPP_0212_SOLUTION1_H
#define CPP_0212_SOLUTION1_H

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {

private:

    struct Node {
        bool isWord = false;
        vector<Node *> children = vector<Node *>(26, nullptr);
    };

    Node *root;
    int m; // 行数
    int n; // 列数
    vector<vector<char>> board;
    vector<vector<bool>> marked;
    vector<int> arri = {0, 0, 1, -1};
    vector<int> arrj = {1, -1, 0, 0};

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }

    void dfs(int i, int j, Node *curNode, string word, set<string> &res) {
        int index = board[i][j] - 'a';
        curNode = curNode->children[index];
        if (curNode) {
            if (curNode->isWord) {
                res.insert(word + board[i][j]);
            }
            marked[i][j] = true;
            string tempWord = word;
            word += board[i][j];
            for (int k = 0; k < 4; ++k) {
                i += arri[k];
                j += arrj[k];
                if (isValid(i, j)) {
                    dfs(i, j, curNode, word, res);
                }
                i -= arri[k];
                j -= arrj[k];
            }
            word = tempWord;
            marked[i][j] = false;
        }
        return;
    }

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && !marked[i][j];
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        this->root = new Node();
        this->m = board.size();
        this->n = board[0].size();
        this->marked = vector<vector<bool>>(m, vector<bool>(n, false));
        this->board = board;

        for (const auto &word : words)
            insert(word);

        set<string> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, root, "", res);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};

#endif //CPP_0212_SOLUTION1_H
