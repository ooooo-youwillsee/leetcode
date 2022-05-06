//
// Created by ooooo on 2020/1/31.
//
#ifndef CPP_0824__SOLUTION2_H_
#define CPP_0824__SOLUTION2_H_

#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

/**
 * 拼接字符串 使用stringstream
 */
class Solution {
 public:
  unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  void help(stringstream &ss, string word, int count, bool space) {
    if (set.count(word[0])) {
      // 元音
      ss << word;
    } else {
      ss << word.substr(1, word.size() - 1) << word.substr(0, 1);
    }
    ss << "ma";
    ss << string(count, 'a');
    if (space) {
      ss << " ";
    }
  }

  string toGoatLatin(string S) {
    int i = 0, j = S.find(" ", i), count = 1;
    stringstream ss;
    while (j != -1) {
      string word = S.substr(i, j - i);
      help(ss, word, count++, true);
      i = j + 1;
      j = S.find(" ", i);
    }
    help(ss, S.substr(i, S.size() - i), count++, false);
    return ss.str();
  }
};

#endif //CPP_0824__SOLUTION2_H_
