/**
 * @author ooooo
 * @date 2020/12/11 10:25 
 */

#ifndef CPP_1662__SOLUTION1_H_
#define CPP_1662__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
		string word_seq1 = "";
		for (auto &item1 : word1) {
			word_seq1 += item1;
		}
		string word_seq2 = "";
		for (auto &item2 : word2) {
			word_seq2 += item2;
		}
		return word_seq1 == word_seq2;
	}
};

#endif //CPP_1662__SOLUTION1_H_
