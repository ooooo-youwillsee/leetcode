/**
 * @author ooooo
 * @date 2021/1/20 13:13 
 */

#ifndef CPP_1721__SOLUTION1_H_
#define CPP_1721__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution {
 public:

	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};

	ListNode *swapNodes(ListNode *head, int k) {
		vector<ListNode *> nums;
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode *cur = dummyHead;
		while (cur) {
			nums.emplace_back(cur);
			cur = cur->next;
		}
		if (nums.size() == 2) return nums[1];
		ListNode *node1 = nums[k];
		ListNode *node2 = nums[nums.size() - k];
		int node1_val = node1->val, node2_val = node2->val;
		node2->val = node1_val;
		node1->val = node2_val;
		return nums[1];
	}
};

#endif //CPP_1721__SOLUTION1_H_
