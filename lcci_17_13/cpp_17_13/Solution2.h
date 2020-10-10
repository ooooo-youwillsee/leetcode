/**
 * @author ooooo
 * @date 2020/10/10 19:30 
 */

#ifndef CPP_17_13__SOLUTION2_H_
#define CPP_17_13__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * trie
 */
class Solution {
 public:

	struct Node {
		vector<Node *> children;
		bool isWord;
		Node() {
			this->children.assign(26, nullptr);
			this->isWord = false;
		}
	};

	Node *root = new Node();

	void buildTree(vector<string> &dict) {
		for (auto &word: dict) {
			Node *cur = root;
			for (int i = word.size() - 1; i >= 0; --i) {
				int k = word[i] - 'a';
				if (!cur->children[k]) {
					cur->children[k] = new Node();
				}
				cur = cur->children[k];
			}
			cur->isWord = true;
		}
	}

	int respace(vector<string> &dictionary, string sentence) {
		int n = sentence.size();
		if (dictionary.empty()) return n;
		buildTree(dictionary);

		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n; i++) {
			dp[i + 1] = dp[i] + 1;
			Node *cur = root;
			int j = i;
			for (; j >= 0; --j) {
				int k = sentence[j] - 'a';
				if (!cur->children[k]) break;
				cur = cur->children[k];
				if (cur->isWord) {
					dp[i + 1] = min(dp[i + 1], dp[j]);
				}
			}
			//cout << "i+1: " << i + 1 << " " << dp[i + 1] << endl;
		}
		return dp[n];
	}
};

#endif //CPP_17_13__SOLUTION2_H_
