// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，
// 并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，
// 该方案中 'Q' 和 '.' 分别代表了皇后和空位。
// 链接：https://leetcode-cn.com/problems/n-queens

// 思路一: 回溯
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return result;
        string s(n, '.');
        vector<string> v(n, s);
        helper(n, 0, v);
        return result;
    }
    void helper(int n, int index, vector<string>& v) {
        if (index >= n) {
            result.push_back(vector<string>(v));
            return;
        }
        for (int i = 0; i < n; ++i) {
            // 处理 v[index][i] 元素；
            int attack = false;
            for (int row = 0; row < index; ++row) {
                for (int col = 0; col < n; ++col) {
                    if ((v[row][col] == 'Q') && (i == col || index + i == row + col || index - i == row - col)) {
                        attack = true;
                        break;
                    }
                }
            }
            if (!attack) {
                v[index][i] = 'Q';
                helper(n, index+1, v);
                v[index][i] = '.';
            }
        }
    }
private:
    vector<vector<string>> result;
};