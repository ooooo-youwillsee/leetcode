/**
 * @author ooooo
 * @date 2020/10/31 17:20 
 */

#ifndef CPP_0381__SOLUTION1_H_
#define CPP_0381__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
 public:

	vector<int> nums;
	// key -> 值， value -> 值的下标
	unordered_map<int, unordered_set<int>> map;
	/** Initialize your data structure here. */
	RandomizedCollection() {
	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool ans = true;
		if (map.find(val) != map.end()) {
			ans = false;
		}
		nums.push_back(val);
		map[val].insert(nums.size() - 1);
		return ans;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (map.find(val) == map.end()) return false;
		int i = *(map[val].begin());
		map[val].erase(i);
		int last_val = nums.back();
		map[last_val].erase(nums.size() - 1);
		if (i < nums.size() - 1) {
			map[last_val].insert(i);
		}
		nums[i] = last_val;
		nums.pop_back();
		if (map[val].empty()) {
			map.erase(val);
		}
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

#endif //CPP_0381__SOLUTION1_H_
