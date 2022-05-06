/**
 * @author ooooo
 * @date 2021/1/20 12:18 
 */

#ifndef CPP_1720__SOLUTION1_H_
#define CPP_1720__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;


class Solution {
 public:
	vector<int> decode(vector<int> &encoded, int first) {
		vector<int> ans = {first};
		for (int i = 0; i < encoded.size(); ++i) {
			ans.push_back(abs(encoded[i] ^ ans.back()));
		}
		return ans;
	}
};

#endif //CPP_1720__SOLUTION1_H_
