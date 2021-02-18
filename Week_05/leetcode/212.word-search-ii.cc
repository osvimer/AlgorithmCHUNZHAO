// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
// 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
// 同一个单元格内的字母在一个单词中不允许被重复使用。
// 链接：https://leetcode-cn.com/problems/word-search-ii

// 思路一：字典树 + DFS
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

// 进一步优化
// 1. 去掉 visited 数组, 改用 board 数组原地标记
// 2. 将 dfs 每次传递的 string 换成 Tire 树的结点指针
class Solution {
    struct TrieNode {
        string word;
        map<char, TrieNode*> child_table;
        TrieNode() {}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.empty() || board.empty() || board[0].empty()) return result;
        rows = board.size();
        cols = board[0].size();

        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* cur = root;
            for (const char& c : word) {
                if (0 == cur->child_table.count(c)) {
                    cur->child_table[c] = new TrieNode();
                }
                cur = cur->child_table[c];
            }
            cur->word = word;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root);
            }
        }
        for (const string& w : found_words) {
            result.push_back(w);
        }
        return result;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        char target = board[i][j];
        if (!root || 0 == root->child_table.count(target)) return;
        root = root->child_table[target];
        if (!root->word.empty()) {
            found_words.insert(root->word);
        }
        board[i][j] = '.';
        for (int k = 0; k < 4; ++k) {
            int x = i + direct[k][0];
            int y = j + direct[k][1];
            if (inBound(x, y) && '.' != board[x][y]) {
                dfs(board, x, y, root);
            }
        }
        board[i][j] = target;
    }
    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
private:
    int rows;
    int cols;
    vector<string> result;
    unordered_set<string> found_words;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};
