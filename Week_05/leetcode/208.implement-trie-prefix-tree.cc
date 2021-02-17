// 实现一个 Trie (前缀树)，包含 insert, search 和 startswith 三个操作。
// 示例:
//     Trie trie = new Trie();
//     trie.insert("apple");
//     trie.search("apple");   // 返回 true
//     trie.search("app");     // 返回 false
//     trie.startsWith("app"); // 返回 true
//     trie.insert("app");   
//     trie.search("app");     // 返回 true
// 说明:
//     你可以假设所有的输入都是由小写字母 a - z 构成的。
//     保证所有输入均为非空字符串。
// https://leetcode-cn.com/problems/implement-trie-prefix-tree
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
