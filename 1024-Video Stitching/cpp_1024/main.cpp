#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {
	Solution solution;
	vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
	auto ans = solution.videoStitching(clips, 10);
	cout << ans << endl;
	return 0;
}
