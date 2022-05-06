/**
 * @author ooooo
 * @date 2021/3/8 20:04 
 */

#ifndef CPP_1733__SOLUTION1_H_
#define CPP_1733__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:

	int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {
		int pNum = languages.size();
		vector<vector<bool>> aux(pNum + 1, vector<bool>(n + 1));
		for (int k = 0; k < languages.size(); ++k) {
			for (auto l: languages[k]) {
				aux[k + 1][l] = true;
			}
		}

		vector<bool> p(pNum + 1);
		for (int j = 0; j < friendships.size(); ++j) {
			int u = friendships[j][0], v = friendships[j][1];
			// 判断有没有公共语言
			bool common = false;
			for (int i = 1; i <= n; ++i) {
				if (aux[u][i] && aux[v][i]) {
					common = true;
					break;
				}
			}
			if (!common) {
				// 说明u和v需要被教语言
				p[u] = true;
				p[v] = true;
			}
		}

		int cnt = 0;
		int total = 0;
		vector<int> lan(n + 1);
		for (int i = 1; i < p.size(); ++i) {
			if (p[i]) {
				for (auto j : languages[i - 1]) {
					lan[j]++;
					cnt = max(cnt, lan[j]);
				}
				total++;
			}
		}

		return total - cnt;
	}

};

#endif //CPP_1733__SOLUTION1_H_
