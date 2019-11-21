#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

int main() {

    set<int> s;
    s.insert(1);
    s.erase(1);
    s.insert(2);
    for (auto item : s) {
        cout << item;
    }
    return 0;
}