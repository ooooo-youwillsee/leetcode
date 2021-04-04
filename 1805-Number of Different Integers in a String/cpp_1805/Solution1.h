/**
 * @author ooooo
 * @date 2021/4/4 08:28 
 */

#ifndef CPP_1805__SOLUTION1_H_
#define CPP_1805__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int numDifferentIntegers(string word) {
		unordered_set<string> set;
		int zero = 0;
		for (int i = 0; i < word.size();) {
			while (i < word.size() && isalpha(word[i])) {
				i++;
			}
			int l = i;
			while (i < word.size() && word[i] >= '0' && word[i] <= '9') {
				i++;
			}
			if (i != l) {
				int k = l;
				while (k < word.size() && word[k] == '0') {
					k++;
				}
				if (k == i) {
					zero = 1;
				} else {
					set.insert(word.substr(k, i - k));
				}
			}
		}
		return set.size() + zero;
	}
};

#endif //CPP_1805__SOLUTION1_H_
