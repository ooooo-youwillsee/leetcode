/**
 * @author ooooo
 * @date 2021/3/25 13:00 
 */

#ifndef CPP_0082__SOLUTION1_H_
#define CPP_0082__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *dummyHead = new ListNode(-1), *node = dummyHead;
		ListNode *cur = head;
		while (cur) {
			ListNode *a = cur->next;
			bool flag = false;
			while (a) {
				if (a->val == cur->val) {
					flag = true;
					a = a->next;
				} else {
					break;
				}
			}
			if (flag) {
				cur = a;
				continue;
			}
			node->next = cur;
			cur = cur->next;
			node = node->next;
			node->next = nullptr;
		}
		return dummyHead->next;
	}
};

#endif //CPP_0082__SOLUTION1_H_
