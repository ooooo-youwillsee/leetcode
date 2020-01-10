//
// Created by ooooo on 2020/1/10.
//
#ifndef CPP_0299__SOLUTION2_H_
#define CPP_0299__SOLUTION2_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    int A = 0, B = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) A++;
      m[secret[i]]++;
    }

    for (int i = 0; i < guess.size(); ++i) {
      if (m[guess[i]]) {
        B++;
        m[guess[i]]--;
      }
    }

    B = A > 0 ? B - A : B;
    return to_string(A) + "A" + to_string(B) + "B";
  }
};

#endif //CPP_0299__SOLUTION2_H_
