//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_0811__SOLUTION1_H_
#define CPP_0811__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  vector<string> split(string s, string sep) {
    vector<string> ans;
    int i = s.find_first_of(" ") + 1;
    ans.push_back(s.substr(i, s.size() - i));
    int j = s.find_first_of(sep, i + 1);
    while (j != -1) {
      ans.push_back(s.substr(j + 1, s.size() - j - 1));
      j = s.find_first_of(sep, j + 1);
    }
    return ans;
  }

  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> m;
    for (const auto &domain: cpdomains) {
      int times = stoi(domain.substr(0, domain.find_first_of(" ")));
      for (const auto &item: split(domain, ".")) {
        m[item] += times;
      }
    }

    vector<string> ans;
    for(const auto &entry: m) {
      ans.push_back(to_string(entry.second) + " " + entry.first);
    }
    return ans;
  }
};

#endif //CPP_0811__SOLUTION1_H_
