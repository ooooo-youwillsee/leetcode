/**
 * @author ooooo
 * @date 2021/3/20 18:52 
 */

#ifndef CPP_1649__SOLUTION2_H_
#define CPP_1649__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

// 树状数组
class Solution {
 public:

	struct BIT {
		vector<int> data, tree;

		BIT(vector<int> data) : data(data.size()), tree(data.size() + 1) {
			for (int i = 0; i < data.size(); ++i) {
				this->data[i] = data[i];
			}

			for (int i = 0; i < data.size(); ++i) {
				set(i, data[i]);
			}
		}

		void set(int i, int v) {
			i++;
			while (i < tree.size()) {
				tree[i] += v;
				i += lowBit(i);
			}
		}

		int query(int i) {
			i++;
			int sum = 0;
			while (i >= 1) {
				sum += tree[i];
				i -= lowBit(i);
			}
			return sum;
		}

		int lowBit(int x) {
			return x & -x;
		}
	};

	static constexpr int MOD = 1e9 + 7;
	int createSortedArray(vector<int> &instructions) {
		vector<int> nums(1e5 + 1);
		BIT tree(nums);

		long long ans = 0;
		for (int i = 0; i < instructions.size(); ++i) {
			int less = tree.query(instructions[i] - 1);
			int greater = i - nums[instructions[i]] - less;
			ans = (ans + min(less, greater)) % MOD;
			nums[instructions[i]]++;
			tree.set(instructions[i], 1);
		}

		return ans;
	}
}

#endif //CPP_1649__SOLUTION2_H_
