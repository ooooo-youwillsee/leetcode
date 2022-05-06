/**
 * @author ooooo
 * @date 2021/1/24 18:00 
 */

#ifndef CPP_1657__SOLUTION1_H_
#define CPP_1657__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
 public:

	vector<int> calcCounts(string word) {
		vector<int> counts(26, 0);
		for (auto &c : word) {
			counts[c - 'a']++;
		}
		return counts;
	}

	bool closeStrings(string word1, string word2) {
		vector<int> count1 = calcCounts(word1);
		vector<int> count2 = calcCounts(word2);
		for (int i = 0; i < 26; ++i) {
			if (count1[i] != count2[i]) {
				if (count2[i] == 0 || count1[i] == 0) return false;
				bool find = false;
				for (int j = i + 1; j < 26; ++j) {
					if (count2[j] == count1[i]) {
						swap(count2[j], count2[i]);
						find = true;
						break;
					}
				}
				if (!find) {
					return false;
				}
			}
		}
		return true;
	}
};

#endif //CPP_1657__SOLUTION1_H_
