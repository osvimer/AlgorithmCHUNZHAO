// 一个机器人位于一个 m x n 网格的左上角
// 机器人每次只能向下或者向右移动一步
// 机器人试图达到网格的右下角
// 问总共有多少条不同的路径？
// https://leetcode-cn.com/problems/unique-paths

// 思路一：动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// 思路二：使用一维数组，减少空间复杂度
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
