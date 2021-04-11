/**
 * @author ooooo
 * @date 2021/4/11 15:31 
 */

#ifndef CPP_1813__SOLUTION1_H_
#define CPP_1813__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
 public:

	bool areSentencesSimilar(string sentence1, string sentence2) {
		auto split = [](const string &s) {
			istringstream in(s);
			string w;
			deque<string> words;
			while (in >> w) {
				words.push_back(w);
			}
			return words;
		};

		if (sentence1.size() < sentence2.size()) swap(sentence1, sentence2);
		deque<string> word1 = split(sentence1), word2 = split(sentence2);
		while (!word2.empty() && word1.front() == word2.front()) {
			word1.pop_front();
			word2.pop_front();
		}
		while (!word2.empty() && word1.back() == word2.back()) {
			word1.pop_back();
			word2.pop_back();
		}
		return word2.empty();
	}
};

#endif //CPP_1813__SOLUTION1_H_
