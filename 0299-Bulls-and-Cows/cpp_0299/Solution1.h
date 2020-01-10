//
// Created by ooooo on 2020/1/10.
//
#ifndef CPP_0299__SOLUTION1_H_
#define CPP_0299__SOLUTION1_H_

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> secretMap, guessMap;
    int A = 0, B = 0;

    for (int i = 0; i < guess.size(); ++i) {
      if (guess[i] == secret[i]) {
        A++;
      } else {
        secretMap[secret[i]]++;
        guessMap[guess[i]]++;
      }
    }

    for (auto &entry: guessMap) {
      char key = entry.first;
      if (secretMap.count(key)) {
        if (secretMap[key] < guessMap[key]) {
          B += secretMap[key];
        } else {
          B += guessMap[key];
        }
      }
    }

    return to_string(A) + "A" + to_string(B) + "B";
  }
};

#endif //CPP_0299__SOLUTION1_H_
