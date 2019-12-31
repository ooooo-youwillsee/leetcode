#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"
//#include "Solution3.h"

void test(string beginWord, string endWord, vector<string> wordList) {
    Solution s;
    //cout<< s.bestMatch("hit", "hox") <<endl;
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}

int main() {

    test("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
    test("hot", "dog", {"hot", "dog", "dot"});
    test("hot", "dot", {"hot","dot","dog"});
    test("a", "c", {"a", "b", "c"});
    test("hot", "dog", {"hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot"});
    test("qa", "sq",
         {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci",
          "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or",
          "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb",
          "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo",
          "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr",
          "pa", "he", "lr", "sq", "ye"});


    return 0;
}

