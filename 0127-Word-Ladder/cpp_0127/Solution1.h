//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_0127_SOLUTION1_H
#define CPP_0127_SOLUTION1_H

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:

    int min = INT_MAX;
    // 加速计算
    unordered_map<string, bool> map;


    bool bestMatch(string currentWord, string beginWord) {
        if (this->map.find(currentWord + beginWord) != this->map.end()) {
            return this->map[currentWord + beginWord];
        } else if (this->map.find(beginWord + currentWord) != this->map.end()) {
            return this->map[beginWord + currentWord];
        }

        bool flag = false;
        for (int j = 0; j < currentWord.size(); ++j) {
            if (currentWord[j] == beginWord[j]) continue;
            if (flag) return false;
            flag = true;
        }
        this->map[currentWord + beginWord] = this->map[beginWord + currentWord] = flag;
        return flag;
    }

    vector<int> findBestMatch(string beginWord, string endWord, vector<string> wordList, vector<bool> &matched) {
        vector<int> res;
        for (int i = 0; i < wordList.size(); ++i) {
            if (matched[i]) continue;
            string currentWord = wordList[i];
            if (bestMatch(currentWord, beginWord)) {
                res.push_back(i);
            }
        }
        return res;
    }


    bool dfs2(string beginWord, string endWord, vector<string> wordList, vector<bool> &matched, int count) {
        if (beginWord == endWord) {
            min = min < count ? min : count;
            return true;
        }
        vector<int> indexList = findBestMatch(beginWord, endWord, wordList, matched);
        for (int i = 0; i < indexList.size(); ++i) {
            matched[indexList[i]] = true;
            dfs2(wordList[indexList[i]], endWord, wordList, matched, count + 1);
            matched[indexList[i]] = false;
        }
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        vector<bool> matched(wordList.size(), false);
        dfs2(beginWord, endWord, wordList, matched, 1);
        return min == INT_MAX ? 0 : min;
    }

};

#endif //CPP_0127_SOLUTION1_H
