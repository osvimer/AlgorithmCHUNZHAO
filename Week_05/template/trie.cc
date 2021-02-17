#include <iostream>
#include <map>
#include <string>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->child_table.count(word[i]) == 0) {
                cur->child_table[word[i]] = new TrieNode();
            }
            cur = cur->child_table[word[i]];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, false);
    }

private:
    bool find(string word, bool strict) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->child_table.count(word[i]) == 0) {
                return false;
            }
            cur = cur->child_table[word[i]];
        }

        return strict ? cur->end : true;
    }

    struct TrieNode {
        map<char, TrieNode*> child_table;
        bool end;
        TrieNode(): end(false) {}
    };

    TrieNode* root;
};

int main(int argc, const char* argv[]) {
    Trie* obj = new Trie();
    obj->insert("banana");
    bool b1 = obj->search("apple");
    bool b2 = obj->search("banana");
    bool b3 = obj->startsWith("ban");
    cout << b1 << b2 << b3 << endl;
    return 0;
}
