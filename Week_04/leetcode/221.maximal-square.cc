// 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

// 思路一：动态规划
// 子问题: 以（i, j) 为右下角的最大正方形边长
// 状态空间 dp[i][j]
// 状态转移方程:
// dp[i][j] = matrix[i][j] == '1' ? min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1 : 0;
// 原始问题的解：dp 数组最大值的平方
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        // 下标从 1 开始，简化边界处理
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                dp[i][j] = matrix[i-1][j-1] == '1' ?
                    min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1 : 0;
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};

// 进一步优化空间复杂度
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        // 下标从 1 开始，简化边界处理
        vector<int> dp(cols + 1, 0);
        int result = 0;
        int north_west = 0; // 西北角的位置
        for (int i = 1; i <= rows; ++i) {
            north_west = 0;
            for (int j = 1; j <= cols; ++j) {
                int next_north_west = dp[j];
                dp[j] = matrix[i-1][j-1] == '1' ? min(min(dp[j], dp[j-1]), north_west) + 1 : 0;
                result = max(result, dp[j]);
                north_west = next_north_west; // 更新西北角的位置
            }
        }
        return result * result;
    }
};
