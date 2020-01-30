//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0819__SOLUTION2_H_
#define CPP_0819__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 *
 */
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_map<string, int> m;
    unordered_set<string> bannedSet(begin(banned), end(banned));
    int i = 0, j = 0;
    string ans = "";
    int max = 0;
    while (true) {
      while (i < paragraph.size() && !isalpha(paragraph[i])) {
        i++;
      }
      while (j < paragraph.size() && isalpha(paragraph[j])) {
        paragraph[j] = tolower(paragraph[j]);
        j++;
      }
      if (j > i) {
        string word = paragraph.substr(i, j - i);
        if (!bannedSet.count(word)) {
          ++m[word];
          // 计数的同时可以比较！！！
          if (max < m[word]) {
            max = m[word];
            ans = word;
          }
        }
        j++;
        i = j;
      } else if (i > j) {
        // j不是字符，可能是','
        j++;
      } else {
        break;
      }
    }

    return ans;
  }
};

#endif //CPP_0819__SOLUTION2_H_
