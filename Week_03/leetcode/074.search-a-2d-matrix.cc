// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// https://leetcode-cn.com/problems/search-a-2d-matrix

// 思路：将二维数组索引转为一维，然后使用二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int lo = 0, hi = rows * cols - 1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int x = mi / cols;
            int y = mi % cols;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return false;
    }
};