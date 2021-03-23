/**
 * @author ooooo
 * @date 2021/3/23 15:55 
 */

#ifndef CPP_0341__SOLUTION1_H_
#define CPP_0341__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
 public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class NestedIterator {
 public:

	vector<int> ans;

	void dfs(vector<NestedInteger> &nestedList, vector<int> &vec) {
		for (int i = 0; i < nestedList.size(); ++i) {
			if (nestedList[i].isInteger()) {
				vec.push_back(nestedList[i].getInteger());
			} else {
				dfs(nestedList[i].getList(), vec);
			}
		}
	}

	int i = 0;
	NestedIterator(vector<NestedInteger> &nestedList) {
		i = 0;
		ans.clear();
		dfs(nestedList, ans);
	}

	int next() {
		return ans[i++];
	}

	bool hasNext() {
		return i < ans.size();
	}
};

#endif //CPP_0341__SOLUTION1_H_
