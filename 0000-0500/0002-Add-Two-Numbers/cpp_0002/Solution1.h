/**
 * @author ooooo
 * @date 2020/10/4 12:43 
 */

#ifndef CPP_0002__SOLUTION1_H_
#define CPP_0002__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
	ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
		ListNode *dummyHead = new ListNode(-1), *cur = dummyHead;
		int carry = 0;
		while (l1 || l2) {
			int v1 = l1 ? l1->val : 0;
			int v2 = l2 ? l2->val : 0;
			cur->next = new ListNode((v1 + v2 + carry) % 10);
			carry = (v1 + v2 + carry) / 10;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
			cur = cur->next;
		}
		if (carry) {
			cur->next = new ListNode(carry);
		}
		return dummyHead->next;
	}

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *dummyHead = new ListNode(-1), *cur = dummyHead;
		int carry = 0;
		while (l1 || l2) {
			int v1 = l1 ? l1->val : 0;
			int v2 = l2 ? l2->val : 0;
			ListNode *node = l1 ? l1 : l2;
			node->val = (v1 + v2 + carry) % 10;
			cur->next = node;
			carry = (v1 + v2 + carry) / 10;
			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
			cur = cur->next;
		}
		if (carry) {
			cur->next = new ListNode(carry);
		}
		return dummyHead->next;
	}
};

#endif //CPP_0002__SOLUTION1_H_
