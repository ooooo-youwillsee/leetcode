/**
 * @author ooooo
 * @date 2021/2/13 14:48 
 */

#ifndef CPP_0068__SOLUTION1_H_
#define CPP_0068__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	string convert(vector<string> &words, int maxWidth, int lastI, int i, bool lastLine) {
		int spaceCount = maxWidth;
		int wordCount = i - lastI + 1;
		int suffixSpaceCount = 1; // 默认为一个空格
		for (int j = lastI; j <= i; ++j) {
			spaceCount -= words[j].size();
		}
		spaceCount -= (wordCount - 1);

		// 可能只有一个单词
		int spaceAvg = wordCount != 1 ? spaceCount / (wordCount - 1) : 0;
		int spaceExtra = 0;
		if (wordCount != 1 && spaceCount % (wordCount - 1) != 0) {
			spaceExtra = spaceCount % (wordCount - 1);
		}

		string line = "";
		for (int j = lastI, k = 0; j <= i - 1; ++j, k++) {
			line += words[j];
			fill_n(back_inserter(line), suffixSpaceCount + spaceAvg + (k < spaceExtra), ' ');
		}
		line += words[i];
		fill_n(back_inserter(line), maxWidth - line.size(), ' ');
		return line;
	}

	vector<string> fullJustify(vector<string> &words, int maxWidth) {
		int sz = words.size();
		int wordCount = 0;

		vector<string> ans;
		for (int i = 0, lastI = 0; i < sz; ++i) {
			// 一个单词最少一个空格
			wordCount += words[i].size() + 1;
			if (i + 1 < sz && wordCount + words[i + 1].size() > maxWidth) {
				ans.emplace_back(convert(words, maxWidth, lastI, i, i == sz - 1));
				wordCount = 0;
				lastI = i + 1;
			} else if (i == sz - 1) {
				ans.emplace_back(getLastLine(maxWidth, i, lastI, words));
			}
		}
		return ans;
	}

	string getLastLine(int maxWidth, int i, int lastI, vector<string> &words) const {
		string line = "";
		for (int k = lastI; k <= i; ++k) {
			line += words[k];
			if (k != i) line += " ";
		}
		fill_n(back_inserter(line), maxWidth - line.size(), ' ');
		return line;
	}

};

#endif //CPP_0068__SOLUTION1_H_
