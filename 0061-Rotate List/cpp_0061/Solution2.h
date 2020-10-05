/**
 * @author ooooo
 * @date 2020/10/5 20:07 
 */

#ifndef CPP_0061__SOLUTION2_H_
#define CPP_0061__SOLUTION2_H_

#include "ListNode.h"

/**
 * 先首尾相连
 */
class Solution {
 public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr || k == 0) return head;
		int len = 1;
		ListNode *cur = head;
		while (cur->next) {
			cur = cur->next;
			len++;
		}
		k %= len;
		if (k == 0) return head;
		cur->next = head;
		cur = head;
		int cnt = len - k - 1;
		while (cnt) {
			cnt--;
			cur = cur->next;
		}
		ListNode *new_head = cur->next;
		cur->next = nullptr;
		return new_head;
	}
};

#endif //CPP_0061__SOLUTION2_H_
