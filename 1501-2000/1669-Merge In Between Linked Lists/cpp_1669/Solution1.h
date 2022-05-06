/**
 * @author ooooo
 * @date 2021/1/24 17:54 
 */

#ifndef CPP_1669__SOLUTION1_H_
#define CPP_1669__SOLUTION1_H_



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

	ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
		ListNode *dummyHead = new ListNode(-1), *cur = dummyHead;
		dummyHead->next = list1;
		while (a > 0) {
			cur = cur->next;
			a--;
			b--;
		}
		ListNode *x = cur;
		while (b >= 0) {
			cur = cur->next;
			b--;
		}
		ListNode *y = cur->next;
		cur = x;
		cur->next = list2;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = y;
		return dummyHead->next;
	}

};
#endif //CPP_1669__SOLUTION1_H_
