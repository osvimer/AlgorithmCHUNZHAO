// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
// 示例:
//      X X X X
//      X O O X
//      X X O X
//      X O X X
// 运行你的函数后，矩阵变为：
//      X X X X
//      X X X X
//      X X X X
//      X O X X
// 解释: 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
// 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
// 如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// https://leetcode-cn.com/problems/surrounded-regions

// 思路一：枚举所有的 'O'，执行 DFS；记录所有访问过的 'O';
//         遇到边界的 'O'，表示岛屿未被包围；
//         否则将所有访问过的点标记为 'X';
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        rows = board.size();
        cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if ('O' == board[i][j] && !visited[i][j]) {
                    if (dfs(board, i, j, visited)) {
                        for (auto& p : path) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                    path.clear();
                }
            }
        }
    }

    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited) {
        path.push_back({i, j});
        visited[i][j] = true;
        if (isBound(i, j)) return false;
        bool surrounded = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + direct[k][0];
            int y = j + direct[k][1];
            if (inBound(x, y) && 'O' == board[x][y] && !visited[x][y]) {
                if (!dfs(board, x, y, visited)) {
                    surrounded = false;
                    //return false;
                }
            }
        }
        return surrounded;
        //return true;
    }

    bool isBound(int i, int j) {
        return 0 == i || i == rows - 1 || 0 == j || j == cols - 1;
    }

    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
private:
    int rows;
    int cols;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<pair<int, int>> path;
};

// 思路二：上面的方法中使用了一个 m * n 的 visited 数组记录 'O' 的访问情况；
//         可稍微优化一下空间复杂度:
//         每次访问过的 'O' 都即使更新为 'X'; 但是仍将其将入 path 数组；
//         单次递归终止时，如果判定区域未被包围；将 path 合并到 wrong_path 数组；
//         最终遍历结束后，将所有 wrong_path 中的 点重新更新为 'O'。
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        // 对每个 ‘0’ 进行 dfs
        // 剪枝：可以忽略外圈的处理
        rows = board.size();
        cols = board[0].size();
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if ('O' == board[i][j]) {
                    if (!dfs(board, i, j)) {
                        wrong_path.push_back(path);
                    }
                    path.clear();
                }
            }
        }
        for (auto& v: wrong_path) {
            for (auto& p : v) {
                board[p.first][p.second] = 'O';
            }
        }
    }

    bool dfs(vector<vector<char>>& board, int i, int j) {
        path.emplace_back(i, j);
        board[i][j] = 'X';
        if (isBound(i, j)) return false;
        bool surrounded = true;
        for (int k = 0; k < 4; ++k) {
            int x = i + direct[k][0];
            int y = j + direct[k][1];
            if (inBound(x, y) && 'O' == board[x][y]) {
                if (!dfs(board, x, y)) {
                    //return false;
                    surrounded = false;
                }
            }
        }
        //return true;
        return surrounded;
    }

    bool isBound(int i, int j) {
        return 0 == i || i == rows - 1 || 0 == j || j == cols - 1;
    }

    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
private:
    int rows;
    int cols;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> wrong_path;
};

// 思路三：从边界的 'O' 向中心做 DFS，所有被访问到的 'O' 即为未包围区域；
//         为避免重复访问；将所有已访问过的 'O' 标记为 '@';
//         待搜索结束；将所有的 'O' 标记为 'X'; '@' 标记为 '@';
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('O' == board[i][j] && isBound(i, j)) {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('O' == board[i][j]) {
                    board[i][j] = 'X';
                } else if ('@' == board[i][j]) {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (!inBound(i, j) || 'O' != board[i][j]) return;
        board[i][j] = '@';
        for (int k = 0; k < 4; ++k) {
            dfs(board, i + direct[k][0], j + direct[k][1]);
        }
    }

    bool isBound(int i, int j) {
        return 0 == i || i == rows - 1 || 0 == j || j == cols - 1;
    }

    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
private:
    int rows;
    int cols;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};
