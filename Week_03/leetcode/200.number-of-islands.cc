// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
// https://leetcode-cn.com/problems/number-of-islands

// 思路一：DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (0 == grid.size() || 0 == grid[0].size()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('1' == grid[i][j]) {
                    count++;
                    dfs(grid, rows, cols, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int rows, int cols, int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || '1' != grid[x][y]) return;
        grid[x][y] = '0';
        dfs(grid, rows, cols, x, y - 1);
        dfs(grid, rows, cols, x, y + 1);
        dfs(grid, rows, cols, x - 1, y);
        dfs(grid, rows, cols, x + 1, y);
    }
};