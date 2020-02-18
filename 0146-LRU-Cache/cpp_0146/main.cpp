#include <iostream>
#include "Solution1.h"

int main() {
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;       // 返回  1
  cache.put(3, 3);
  cout << cache.get(2) << endl;       // 返回 -1 (未找到)
  cache.put(4, 4);
  cache.put(5, 5);
  cout << cache.get(1) << endl;       // 返回 -1 (未找到)
  cache.put(6, 6);
  cout << cache.get(3) << endl;       // 返回  3
  cout << cache.get(4) << endl;       // 返回  4
  cout << cache.get(5) << endl;       // 返回  4
  cout << cache.get(6) << endl;       // 返回  4

  return 0;
}
