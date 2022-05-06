//
// Created by ooooo on 2019/12/4.
//
#ifndef CPP_0079_SOLUTION1_H
#define CPP_0079_SOLUTION1_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {

private:

    vector<vector<bool>> marked;
    int m; // 行
    int n; // 列
    string word;
    vector<int> arri = {0, 0, 1, -1};
    vector<int> arrj = {1, -1, 0, 0};


    bool dfs(vector<vector<char>> &board, int i, int j, int start) {
        if (start == word.size() - 1) {
            return word[start] == board[i][j];
        }

        if (word[start] == board[i][j]) {
            marked[i][j] = true;
            for (int k = 0; k < 4; k++) {
                i = i + arri[k];
                j = j + arrj[k];
                if (inArea(i, j) && !marked[i][j] && dfs(board, i, j, start + 1)) {
                    return true;
                }
                i = i - arri[k];
                j = j - arrj[k];
            }
            marked[i][j] = false;
        }

        return false;
    }

    bool inArea(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) return false;
        m = board.size();
        n = board[0].size();
        this->word = word;
        marked = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (dfs(board, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

#endif //CPP_0079_SOLUTION1_H
