/**
 * @author ooooo
 * @date 2020/9/25 22:36 
 */

#ifndef CPP_0023__SOLUTION1_H_
#define CPP_0023__SOLUTION1_H_

#endif //CPP_0023__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:

	struct Comp {
		bool operator()(const ListNode * __x, const ListNode * __y) const { return __x->val >= __y->val; }
	};

	ListNode *mergeKLists(vector<ListNode *> &lists) {

		priority_queue<ListNode *, vector<ListNode *>, Comp> q;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i]) {
				q.push(lists[i]);
			}
		}

		ListNode *dummyHead = new ListNode(), *cur = dummyHead;
		while (!q.empty()) {
			auto node = q.top();
			q.pop();
			cur->next = node;
			cur = cur->next;
			if (node->next)
				q.push(node->next);
		}

		return dummyHead->next;
	}
};
