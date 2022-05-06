#include <iostream>

#include "Solution1.h"

int main() {

    //["Trie","insert","search","search","startsWith","insert","search"]
    Trie *trie = new Trie();
    trie->insert("insert");
    cout << trie->search("insert");
    return 0;
}