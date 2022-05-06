/**
 * @author ooooo
 * @date 2020/11/9 08:58 
 */

#ifndef CPP_0973__SOLUTION1_H_
#define CPP_0973__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * heap
 */
class Solution {
 public:

	struct Item {
		vector<int> point;
		Item(vector<int> &point) {
			this->point = point;
		}

		vector<int> toPoint() const {
			return this->point;
		}

		long distance() const {
			int x = this->point[0], y = this->point[1];
			return x * x + y * y;
		}

		bool operator<(const Item &__y) const {
			return this->distance() > __y.distance();
		}
	};

	vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
		priority_queue<Item> q;
		vector<vector<int>> ans;
		for (auto &p: points) {
			q.push(Item{p});
		}
		while (K) {
			ans.emplace_back(q.top().toPoint());
			q.pop();
			K--;
		}
		return ans;
	}
};

#endif //CPP_0973__SOLUTION1_H_
