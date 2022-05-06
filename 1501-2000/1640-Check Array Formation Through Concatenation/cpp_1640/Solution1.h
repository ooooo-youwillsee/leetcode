/**
 * @author ooooo
 * @date 2020/11/15 09:33 
 */

#ifndef CPP_1640__SOLUTION1_H_
#define CPP_1640__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

class Solution {
 public:

	bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
		unordered_map<int, vector<int>> map;
		for (auto &piece: pieces) {
			map[piece[0]] = piece;
		}
		for (int i = 0; i < arr.size();) {
			if (map.find(arr[i]) == map.end()) return false;
			for (auto &num :map[arr[i]]) {
				if (arr[i] != num) return false;
				i++;
			}
		}
		return true;
	}
}

#endif //CPP_1640__SOLUTION1_H_
