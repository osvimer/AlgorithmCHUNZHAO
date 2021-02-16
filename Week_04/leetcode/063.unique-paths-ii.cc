// 一个机器人位于一个 m x n 网格的左上角
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
// https://leetcode-cn.com/problems/unique-paths-ii

// 思路一：DP（二维数组）
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // 横、纵坐标分别从 1 开始，简化边界处理，且更加直观；
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 注意 obstacleGrid 的横纵坐标是从 i-1 开始
                if (1 == obstacleGrid[i-1][j-1]) {
                    dp[i][j] = 0;
                } else {
                    if (i == 1 && j == 1) {
                        dp[i][j] = 1; // 起始位置
                    } else {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

// 思路二：DP（一维数组）
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (1 == obstacleGrid[i-1][j-1]) {
                    dp[j] = 0;
                } else {
                    if (i == 1 && j == 1) {
                        dp[j] = 1;
                    } else {
                        dp[j] += dp[j-1];
                    }
                }
            }
        }
        return dp[n];
    }
};
