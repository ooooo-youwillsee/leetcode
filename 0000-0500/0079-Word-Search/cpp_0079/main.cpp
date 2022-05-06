#include <iostream>
#include "Solution1.h"

int main() {
    //vector<vector<char>> board =
    //        {
    //                {'A', 'B', 'C', 'E'},
    //                {'S', 'F', 'C', 'S'},
    //                {'A', 'D', 'E', 'E'}
    //        };

    //vector<vector<char>> board = {{'a'}};

    vector<vector<char>> board = {
            {'b', 'a', 'a', 'b', 'a', 'b'},
            {'a', 'b', 'a', 'a', 'a', 'a'},
            {'a', 'b', 'a', 'a', 'a', 'b'},
            {'a', 'b', 'a', 'b', 'b', 'a'},
            {'a', 'a', 'b', 'b', 'a', 'b'},
            {'a', 'a', 'b', 'b', 'b', 'a'},
            {'a', 'a', 'b', 'a', 'a', 'b'}
    };

    Solution s;
    cout << s.exist(board, "ABCCED") << endl;
    cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
    //cout << s.exist(board, "a") << endl;
    cout << s.exist(board, "aabbbbabbaababaaaabababbaaba") << endl;



    // string + char
    //string ss = "";
    //char a = 'A';
    //ss += a;
    //cout << ss << endl;
    return 0;
}