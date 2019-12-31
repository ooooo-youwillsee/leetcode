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

private:

    struct Pair {
        vector<string> res;
        bool find = false;
    };

public:

    bool bestMatch(string currentWord, string beginWord) {
        if (currentWord == beginWord) return true;
        bool flag = false;
        for (int j = 0; j < currentWord.size(); ++j) {
            if (currentWord[j] == beginWord[j]) continue;
            if (flag) return false;
            flag = true;
        }
        return flag;
    }

    unordered_set<string> findBestMatch(string beginWord, vector<string> wordList,
                                        unordered_map<string, int> &visited, int depth) {
        unordered_set<string> res;
        bool find = false;
        for (int i = 0; i < wordList.size(); ++i) {
            string currentWord = wordList[i];
            if (visited.count(currentWord)) continue;
            if (bestMatch(currentWord, beginWord)) {
                visited[currentWord] = depth;
                res.insert(currentWord);
            }
        }
        return res;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, int> visited;
        int depth = 1, find = 0;
        unordered_set<string> words = findBestMatch(beginWord, wordList, visited, depth);
        while (!words.empty()) {
            depth += 1;
            unordered_set<string> container;
            for (auto item: words) {
                unordered_set<string> matches = findBestMatch(item, wordList, visited, depth);
                for(auto w: matches) {
                    if (w == endWord) {
                        return visited[endWord] + 1;
                    }
                }
                container.insert(matches.begin(), matches.end());
            }
            words = container;
        }
        for (auto entry: visited) {
            cout << entry.first << "->" << entry.second << "; ";
        }
        cout << endl;
        return visited.count(endWord) ? visited[endWord] + 1 : 0;

    }

};

#endif //CPP_0127_SOLUTION2_H
