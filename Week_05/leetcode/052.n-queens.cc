// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
// https://leetcode-cn.com/problems/n-queens-ii

// 思路：DFS + 位运算
// 三个整数 col_bits, pie_bits, naa_bits 记录列、撇、捺方向上皇后出现的情况。
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0);
        return result;
    }
    void dfs(int n, int row) {
        if (row >= n) {
            result++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            int pie = row - col + n - 1;
            int naa = row + col;
            if (((col_bits >> col) | (pie_bits >> pie) | (naa_bits >> naa)) & 1) {
                continue;
            }
            col_bits |= (1 << col);
            pie_bits |= (1 << pie);
            naa_bits |= (1 << naa);
            dfs(n, row + 1);
            col_bits ^= (1 << col);
            pie_bits ^= (1 << pie);
            naa_bits ^= (1 << naa);
        }
    }
private:
    int result = 0;
    int col_bits = 0;
    int pie_bits = 0;
    int naa_bits = 0;
};
