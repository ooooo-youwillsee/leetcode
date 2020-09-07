/**
 * @author ooooo
 * @date 2020/9/7 11:08 
 */

#ifndef CPP_0347__SOLUTION2_H_
#define CPP_0347__SOLUTION2_H_

#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Solution {
 public:

	template <typename T>
	struct comp{
		bool operator()(const T &p1, const T &p2) const {
			return p2.second > p1.second;
		}
	};

	vector<int> topKFrequent(vector<int> &nums, int k) {
		map<int, int> m;
		for (auto num : nums) m[num]++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, comp<pair<int,int>>> q;
		for (auto[k, v]: m) {
			q.push({k, v});
		}

		vector<int> ans;
		while (k > 0) {
			ans.push_back(q.top().first);
			q.pop();
			k--;
		}
		return ans;
	}
};

#endif //CPP_0347__SOLUTION2_H_
