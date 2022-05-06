#include <iostream>
#include "Solution1.h"

int main() {
    vector<vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};

    //vector<vector<char>> board = {
    //        {'a'}
    //};
    //vector<string> words = {"a"};

    Solution s;
    vector<string> res = s.findWords(board, words);
    for (const auto &item : res) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}