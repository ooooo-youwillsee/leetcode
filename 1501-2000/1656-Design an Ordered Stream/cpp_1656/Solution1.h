/**
 * @author ooooo
 * @date 2021/1/24 17:58 
 */

#ifndef CPP_1656__SOLUTION1_H_
#define CPP_1656__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class OrderedStream {
 public:
	int ptr;
	vector<string> stream;
	OrderedStream(int n) {
		this->ptr = 1;
		stream.assign(n + 1, "");
	}

	vector<string> insert(int id, string value) {
		stream[id] = value;
		if (stream[ptr] != "") {
			vector<string> ans;
			for (int i = ptr; i < stream.size(); ++i) {
				if (stream[i] == "") {
					break;
				}
				ans.emplace_back(stream[i]);
				ptr = i + 1;
			}
			return ans;
		}
		return {};
	}
};

#endif //CPP_1656__SOLUTION1_H_
