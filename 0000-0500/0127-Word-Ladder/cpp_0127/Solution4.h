/**
 * @author ooooo
 * @date 2020/11/5 17:13 
 */

#ifndef CPP_0127__SOLUTION4_H_
#define CPP_0127__SOLUTION4_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:

	// 返回符合条件的字符串数组，是超时的
	vector<string> diffOneLetter(string &s1, unordered_set<string> &wordSet, unordered_set<string> visited) {
		vector<string> words;
		for (int i = 0; i < s1.size(); ++i) {
			char c = s1[i];
			for (int j = 'a'; j <= 'z'; ++j) {
				s1[i] = j;
				if (!visited.count(s1) && wordSet.count(s1)) {
					words.push_back(s1);
				}
			}
			s1[i] = c;
		}
		return words;
	}

	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		unordered_set<string> visited, wordSet(wordList.begin(), wordList.end());
		visited.insert(beginWord);
		queue<string> q;
		q.push(beginWord);
		int level = 0;
		while (!q.empty()) {
			level += 1;
			for (int i = q.size(); i > 0; --i) {
				string u = q.front();
				q.pop();
				if (u == endWord) {
					return level;
				}
				auto diffWordList = diffOneLetter(u, wordSet, visited);
				for (auto &v :diffWordList) {
					visited.insert(v);
					q.push(v);
				}
			}
		}
		return 0;
	}
};

#endif //CPP_0127__SOLUTION4_H_
