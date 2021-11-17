/**
 * 
 * @author <a href="https://github.com/ooooo-youwillsee">ooooo</a>
 * @date 2021/11/17 19:50
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  int maxProfit = 0;
  unordered_map<int, vector<pair<int, int>>> g;
  unordered_set<int> s;
  vector<int> values;

  void dfs(int i, int profit, int time) {
    if (time < 0) {
      return;
    }

    bool visited = s.count(i);

    if (!visited) {
      profit += values[i];
      s.insert(i);
    }

    if (i == 0) {
      maxProfit = max(profit, maxProfit);
    }

    for (auto &pair: g[i]) {
      int u = pair.first, w = pair.second;
      if (time - w < 0) continue;
      dfs(u, profit, time - w);
    }

    if (!visited) {
      s.erase(i);
    }
  }

  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime) {
    this->values = values;
    for (auto &edge: edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      g[u].push_back(make_pair(v, w));
      g[v].push_back(make_pair(u, w));
    }

    dfs(0, 0, maxTime);
    return maxProfit;
  }
};

int main() {
  Solution solution;

  vector<int> values = {0, 32, 10, 43};
  vector<vector<int>> edges = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
  int maxTime = 49;
  cout << solution.maximalPathQuality(values, edges, maxTime);
  return 0;
}
