// 让我们一起来玩扫雷游戏！
// 给定一个代表游戏板的二维字符矩阵。 
// 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，
// 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
// 数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，
// 'X' 则表示一个已挖出的地雷。

// 根据以下规则，返回相应位置被点击后对应的面板：
// 1. 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
// 2. 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），
//    并且所有和其相邻的未挖出方块都应该被递归地揭露。
// 3. 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，
//    修改它为数字（'1'到'8'），表示相邻地雷的数量。
// 4. 如果在此次点击中，若无更多方块可被揭露，则返回面板。

// 示例 1：
// 输入: 
//      [['E', 'E', 'E', 'E', 'E'],
//       ['E', 'E', 'M', 'E', 'E'],
//       ['E', 'E', 'E', 'E', 'E'],
//       ['E', 'E', 'E', 'E', 'E']]
//       Click : [3,0]
// 输出: 
//      [['B', '1', 'E', '1', 'B'],
//       ['B', '1', 'M', '1', 'B'],
//       ['B', '1', '1', '1', 'B'],
//       ['B', 'B', 'B', 'B', 'B']]

// https://leetcode-cn.com/problems/minesweeper

思路一：DFS
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return board;
        vector<vector<int>> directions({{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}});
        int row = click[0], col = click[1];
        if ('M' == board[row][col]) {
            board[row][col] = 'X';
        } else {
            dfs(board, directions, row, col);
        }
        return board;
    }
    void dfs(vector<vector<char>>& board, vector<vector<int>>& directions, int row, int col) {
        if (!inBound(board, row, col) || 'E' != board[row][col]) {
            return;
        }
        int mines = 0;
        for (auto& d: directions) {
            int x = row + d[0], y = col + d[1];
            if (inBound(board, x, y) && 'M' == board[x][y]) {
                mines++;
            }
        }
        if (0 == mines) {
            board[row][col] = 'B';
            for (auto& d : directions) {
                int x = row + d[0], y = col + d[1];
                if (inBound(board, x, y)) {
                    dfs(board, directions, x, y);
                }
            }
        } else {
            board[row][col] = '0' - 0 + mines;
            return;
        }
    }
    bool inBound(vector<vector<char>>& board, int row, int col) {
        return 0 <= row && row < board.size() && 0 <= col && col < board[0].size();
    }
};