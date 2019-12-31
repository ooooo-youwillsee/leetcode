#include <iostream>
#include "Solution1.h"

void test(string beginWord, string endWord, vector<string> wordList) {
    Solution s;
    //cout<< s.bestMatch("hit", "hox") <<endl;
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}

int main() {

    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
    test("hot", "dog", {"hot", "dog", "dot"});
    test("a", "c", {"a", "b", "c"});
    test("hot", "dog", {"hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot"});


    return 0;
}

