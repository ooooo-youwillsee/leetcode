/**
 * @author ooooo
 * @date 2021/2/26 13:28 
 */

#ifndef CPP_1178__SOLUTION1_H_
#define CPP_1178__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
		// 对words去重, 其中int为每个word单词表示，重复的单词数加1
		unordered_map<int, int> wordMap;
		for (int i = 0; i < words.size(); ++i) {
			int bit = 0;
			for (int j = 0; j < words[i].size(); ++j) {
				int c = words[i][j] - 'a';
				bit |= (1 << c);
			}
			wordMap[bit]++;
		}

		vector<int> ans(puzzles.size(), 0);
		for (int i = 0; i < puzzles.size(); ++i) {
			int cnt = 0;


			// 每个字符串逐一匹配 (低效操作)
			/*for (auto[word, count]: wordMap) {
				// word 没有第一个字符
				if (((1 << (puzzles[i][0] - 'a')) & word) == 0) {
					continue;
				}
				if (bitset<26>(word & mask).count() == bitset<26>(word).count()) {
					cnt += count;
				}
			}*/

			int mask = 0;
			for (int j = 1; j < 7; ++j) {
				mask |= (1 << (puzzles[i][j] - 'a'));
			}
			int subset = mask;
			do {
				int s = subset | (1 << (puzzles[i][0] - 'a'));
				if (wordMap.count(s)) {
					cnt += wordMap[s];
				}
				// 就取mask为1的位置
				subset = (subset - 1) & mask;
			} while (subset != mask);

			ans[i] = cnt;
		}
		return ans;
	}
};

#endif //CPP_1178__SOLUTION1_H_
