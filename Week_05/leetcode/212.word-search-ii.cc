#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
    class Trie {
        struct TrieNode {
            string word;
            map<char, shared_ptr<TrieNode>> child_table;
            TrieNode(): word("") {}
        };

    public:
        Trie() {
            root = make_shared<TrieNode>();
        }

        void insert(const string& word) {
            shared_ptr<TrieNode> cur = root;
            for (const char& c : word) {
                if (0 == cur->child_table.count(c)) {
                    cur->child_table[c] = make_shared<TrieNode>();
                }
                cur = cur->child_table[c];
            }
            cur->word = word;
        }

        bool search(const string& word) {
            return find(word, true);
        }

        bool startsWith(const string& prefix) {
            return find(prefix, false);
        }

    private:
        bool find(const string& word, bool strict) {
            shared_ptr<TrieNode> cur = root;
            for (const char& c : word) {
                if (0 == cur->child_table.count(c)) {
                    return false;
                }
                cur = cur->child_table[c];
            }
            return strict ? !cur->word.empty() : true;
        }

        shared_ptr<TrieNode> root;
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty() || board.empty() || board[0].empty()) return result;
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        trie = make_shared<Trie>();
        for (string& word : words) {
            trie->insert(word);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, string(1, board[i][j]), visited);
            }
        }
        for (const string& w : found_words) {
            result.push_back(w);
        }
        return result;
    }
    void dfs(vector<vector<char>>& board, int i, int j, const string& str, vector<vector<bool>>& visited) {
        if (!trie->startsWith(str)) return;
        if (trie->search(str)) {
            found_words.insert(str);
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + direct[k][0];
            int y = j + direct[k][1];
            if (inBound(x, y) && !visited[x][y]) {
                dfs(board, x, y, str + board[x][y], visited);
            }
        }
        visited[i][j] = false;
    }
    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
private:
    int rows;
    int cols;
    vector<string> result;
    set<string> found_words;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


    shared_ptr<Trie> trie;
};

int main(int argc, const char* argv[]) {
    vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    vector<string> words = {"abc", "bdc"};
    Solution s;
    vector<string> result = s.findWords(board, words);
    for (auto& str : result) {
        cout << str << endl;
    }
}
