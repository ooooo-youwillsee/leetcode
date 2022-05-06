/**
 * @author ooooo
 * @date 2020/11/13 21:07 
 */

#ifndef CPP_0328__SOLUTION1_H_
#define CPP_0328__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
	ListNode *oddEvenList(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *odd = head, *even = head->next, *even_head = head->next;
		ListNode *prev_odd = nullptr;
		while (even) {
			odd->next = even->next;
			prev_odd = odd;
			odd = odd->next;
			if (odd) {
				even->next = odd->next;
				even = even->next;
			} else {
				break;
			}
		}
		if (odd) {
			odd->next = even_head;
		} else {
			prev_odd->next = even_head;
		}
		return head;
	}
};

#endif //CPP_0328__SOLUTION1_H_
