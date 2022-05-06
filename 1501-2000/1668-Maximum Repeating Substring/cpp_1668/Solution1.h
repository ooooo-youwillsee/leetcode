/**
 * @author ooooo
 * @date 2021/1/24 17:52 
 */

#ifndef CPP_1668__SOLUTION1_H_
#define CPP_1668__SOLUTION1_H_
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution {
 public:
	int maxRepeating(string sequence, string word) {
		int ans = 0;
		int max_count = sequence.size() / word.size();
		vector<string> str_vec(max_count + 1);
		str_vec[0] = word;

		for (int i = 1; i < str_vec.size(); ++i) {
			if (sequence.find(str_vec[i - 1]) != -1) {
				ans = max(ans, i);
			}
			str_vec[i] = str_vec[i - 1] + word;
		}
		return ans;
	}

};

#endif //CPP_1668__SOLUTION1_H_
