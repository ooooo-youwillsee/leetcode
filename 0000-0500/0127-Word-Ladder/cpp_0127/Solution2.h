//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0127_SOLUTION2_H
#define CPP_0127_SOLUTION2_H


#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {

public:

    unordered_set<string> findBestMatch(string beginWord, unordered_set<string> wordSet,
                                        unordered_map<string, int> &visited, int depth) {
        unordered_set<string> res;
        for (int i = 0; i < beginWord.size(); ++i) {
            string s = beginWord;
            for (int j = 'a'; j < 'z'; ++j) {
                s[i] = j;
                if (!wordSet.count(s) || visited.count(s)) continue;
                visited[s] = depth;
                res.insert(s);
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> visited;
        int depth = 1;
        unordered_set<string> words = findBestMatch(beginWord, wordSet, visited, depth);
        while (!words.empty()) {
            depth += 1;
            unordered_set<string> container;
            for (auto item: words) {
                unordered_set<string> matches = findBestMatch(item, wordSet, visited, depth);
                if (visited.count(endWord)) return visited[endWord] + 1;
                container.insert(matches.begin(), matches.end());
            }
            words = container;
        }
        //for (auto entry: visited) {
        //    cout << entry.first << "->" << entry.second << "; ";
        //}
        //cout << endl;
        return 0;
    }

};

#endif //CPP_0127_SOLUTION2_H
