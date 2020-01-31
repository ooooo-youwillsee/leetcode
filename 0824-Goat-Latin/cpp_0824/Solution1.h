//
// Created by ooooo on 2020/1/31.
//
#ifndef CPP_0824__SOLUTION1_H_
#define CPP_0824__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 拼接字符串效率低
 */
class Solution {
 public:

  string help(string word, int i, bool space) {
    string newWord = "";
    char firstChar = tolower(word[0]);
    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' ||
        firstChar == 'o' || firstChar == 'u') {
      newWord = word.append("ma").append(string(i, 'a'));
    } else {
      newWord = word.substr(1, word.size() - 1) + word.substr(0, 1);
      newWord.append("ma").append(string(i, 'a'));
    }
    if (space) {
      newWord.append(" ");
    }
    return newWord;
  }

  string toGoatLatin(string S) {
    int i = 0, j = S.find(" ", i), count = 1;
    string ans = "";
    while (j != -1) {
      string word = S.substr(i, j - i);
      ans += help(word, count++, true);
      i = j + 1;
      j = S.find(" ", i);
    }
    ans += help(S.substr(i, S.size() - i), count++, false);
    return ans;
  }
};

#endif //CPP_0824__SOLUTION1_H_
