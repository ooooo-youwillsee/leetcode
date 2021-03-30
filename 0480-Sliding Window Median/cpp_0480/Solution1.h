/**
 * @author ooooo
 * @date 2021/3/30 17:06 
 */

#ifndef CPP_0480__SOLUTION1_H_
#define CPP_0480__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
 public:

	class Median {
	 public:
		int minSize = 0, maxSize = 0;
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		unordered_map<int,int> deleteMap;


		double getMedian() {
			if (minSize == maxSize) {
				return ((long long) left.top() + (long long)right.top()) /2.0;
			}
			return left.top() * 1.0;
		}

		void insert(int x) {
			if (left.empty() || x <= left.top()) {
				left.push(x);
				minSize++;
			}else {
				right.push(x);
				maxSize ++;
			}
			rebalance();
		}

		void rebalance() {
			if (maxSize > minSize) {
				int x = right.top();
				right.pop();
				maxSize--;
				minSize++;
				left.push(x);
				prune(right);
			}else if (minSize -1 > maxSize) {
				int x = left.top();
				left.pop();
				minSize--;
				maxSize++;
				right.push(x);
				prune(left);
			}
		}

		template<class T>
		void prune(T &pq) {
			while(!pq.empty()) {
				int x = pq.top();
				if (deleteMap[x]) {
					deleteMap[x]--;
					pq.pop();
				}else {
					break;
				}
			}
		}

		void erese(int x) {
			deleteMap[x] ++;
			if (x <= left.top()) {
				minSize--;
				prune(left);
			}else {
				maxSize--;
				prune(right);
			}
			rebalance();
		}

	};

	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> ans;
		Median m;
		int n = nums.size();
		for(int i = 0; i < k; i++) {
			m.insert(nums[i]);
		}
		ans.push_back(m.getMedian());
		for(int i = k ; i < n; i++) {
			m.erese(nums[i-k]);
			m.insert(nums[i]);
			ans.push_back(m.getMedian());
		}
		return ans;
	}



};

#endif //CPP_0480__SOLUTION1_H_
