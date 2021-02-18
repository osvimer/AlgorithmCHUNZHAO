// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 数独部分空格内已填入了数字，空白格用 '.' 表示。
// https://leetcode-cn.com/problems/valid-sudoku

// 使用三个 bitset 数组分别记录每行、列、宫中各数字是否出现
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> rows[9], cols[9], cells[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' == board[i][j]) continue;
                int num = board[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                if (rows[i].test(num) || cols[j].test(num) || cells[k].test(num)) {
                    return false;
                }
                rows[i].set(num);
                cols[j].set(num);
                cells[k].set(num);
            }
        }
        return true;
    }
};
