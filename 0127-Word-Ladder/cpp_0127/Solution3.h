//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0127_SOLUTION3_H
#define CPP_0127_SOLUTION3_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        visited.insert(beginWord);
        q.push(beginWord);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            depth += 1;
            while (size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.size(); ++i) {
                    string s = word;
                    for (int j = 'a'; j < 'z'; ++j) {
                        s[i] = j;
                        if (!set.count(s) || visited.count(s)) continue;
                        if (s == endWord) return depth;
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return 0;
    }
};

#endif //CPP_0127_SOLUTION3_H
