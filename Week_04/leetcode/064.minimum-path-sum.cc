// 给定一个包含非负整数的 m x n 网格 grid ，
// 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

// 动态规划，自底向上
// path[i][j] 表示从左上角到第 grid[i][j] 的最小路径和
// 状态转移方程：
//    path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> path(grid);
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 1; i < rows; ++i) {
            path[i][0] += path[i - 1][0];
        }
        for (int i = 1; i < cols; ++i) {
            path[0][i] += path[0][i - 1];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                path[i][j] += min(path[i - 1][j], path[i][j - 1]);
            }
        }
        return path[rows - 1][cols - 1];
    }
};
