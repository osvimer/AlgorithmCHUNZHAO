// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
// 链接：https://leetcode-cn.com/problems/n-queens

// DFS：逐行求解，判断每一个位置在列、撇、捺方向上是否能被攻击。
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        dfs(queens, n, 0);
        return result;
    }
    void dfs(vector<string>& queens, int n, int row) {
        if (row > n - 1) {
            result.push_back(queens);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!canAttack(queens, n, row, col)) {
                queens[row][col] = 'Q';
                dfs(queens, n, row + 1);
                queens[row][col] = '.';
            }
        }
    }
    bool canAttack(vector<string>& queens, int n, int row, int col) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('Q' == queens[i][j] &&
                    (j == col || i + j == row + col || i - j == row - col)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<string>> result;
};
