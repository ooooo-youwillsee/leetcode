#include <iostream>
#include "Solution1.h"

void test() {
  MyHashSet *hashSet = new MyHashSet();
  hashSet->add(1);
  hashSet->add(2);
  cout << hashSet->contains(1) << endl; // 返回 true
  cout << hashSet->contains(3) << endl; // 返回 false (未找到)
  hashSet->add(2);
  cout << hashSet->contains(2) << endl; // 返回 true
  hashSet->remove(2);
  cout << hashSet->contains(2) << endl; // 返回  false (已经被删除)
}

//["MyHashSet","add","remove","add","remove","remove","add","add","add","add","remove"]
//[[],[9],[19],[14],[19],[9],[0],[3],[4],[0],[9]]

void test2() {
  MyHashSet *hashSet = new MyHashSet();
  hashSet->add(9);
  hashSet->remove(19);
  hashSet->add(14);
  hashSet->remove(19);
  hashSet->remove(9);
  hashSet->add(0);
  hashSet->add(3);
  hashSet->add(4);
  hashSet->add(0);
  hashSet->remove(0);
  //cout << hashSet->contains(1) << endl; // 返回 true
  //cout << hashSet->contains(3) << endl; // 返回 false (未找到)
  //hashSet->add(2);
  //cout << hashSet->contains(2) << endl; // 返回 true
  //cout << hashSet->contains(2) << endl; // 返回  false (已经被删除)
}

int main() {
  test2();
  return 0;
}
