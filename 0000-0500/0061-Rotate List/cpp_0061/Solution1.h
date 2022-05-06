/**
 * @author ooooo
 * @date 2020/10/5 18:03 
 */

#ifndef CPP_0061__SOLUTION1_H_
#define CPP_0061__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k == 0) return head;
		int len = 0;
		ListNode * cur = head;
		while (cur) {
			cur = cur->next;
			len++;
		}
		k %= len;
		if (k == 0) return head;

		cur = head;
		int cnt = len - k;
		while (cur && cnt) {
			cnt--;
			cur = cur->next;
		}
		ListNode *new_head = cur->next, *prev = new_head;
		cur->next = nullptr;
		while (prev->next) {
			prev = prev->next;
		}
		prev->next = head;
		return new_head;
	}
};

#endif //CPP_0061__SOLUTION1_H_
