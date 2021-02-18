// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。
// https://leetcode-cn.com/problems/number-of-islands

// 思路：DFS
//       对每个 '1' 沿上下左右四个方向进行深度优先搜索，遇到 '1' 标记为 '0'
//       最后 '1' 的数目就是纵的岛屿的数目
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        rows = grid.size();
        cols = grid[0].size();

        int result = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('1' == grid[i][j]) {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (!inBound(i, j) || '0' == grid[i][j]) return;
        grid[i][j] = '0';
        for (int k = 0; k < 4; ++k) {
            dfs(grid, i + direct[k][0], j + direct[k][1]);
        }
    }
private:
    int rows;
    int cols;
    int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool inBound(int i, int j) {
        return 0 <= i && i < rows && 0 <= j && j < cols;
    }
};
