//
// Created by ooooo on 2020/2/1.
//
#ifndef CPP_0937__SOLUTION1_H_
#define CPP_0937__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 private:

  struct Word {
    // 标识符
    string prefix;
    // 标识符后面的字符
    string rest;
    // 完整的字符串
    string completeStr;

    Word(const string &prefix, const string &rest, const string &complete_str)
        : prefix(prefix), rest(rest), completeStr(complete_str) {}

    Word() {}
    bool operator()(const Word &word1, const Word &word2) const {
      if (word1.rest == word2.rest) {
        return word1.prefix < word2.prefix;
      }
      return word1.rest < word2.rest;
    }
  };

 public:

  vector<string> reorderLogFiles(vector<string> &logs) {
    // log1存放数字log
    vector<string> log1;
    vector<Word> log2;
    for (auto log: logs) {
      if (isdigit(log[log.size() - 1])) {
        log1.push_back(log);
      } else {
        int first_space_i = log.find(" ");
        Word word(log.substr(0, first_space_i),
                  log.substr(first_space_i + 1,
                             log.size() - first_space_i - 1), log);
        log2.push_back(word);
      }
    }

    sort(log2.begin(), log2.end(), Word());

    vector<string> ans;
    for (auto &word: log2) {
      ans.push_back(word.completeStr);
    }
    ans.insert(ans.end(), log1.begin(), log1.end());
    return ans;
  }
};

#endif //CPP_0937__SOLUTION1_H_
