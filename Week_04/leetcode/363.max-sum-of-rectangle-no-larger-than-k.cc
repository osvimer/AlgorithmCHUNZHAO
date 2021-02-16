// 给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。
// 示例:
//    输入: matrix = [[1,0,1],[0,-2,3]], k = 2
//    输出: 2
//    解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
// 说明：
//    1. 矩阵内的矩形区域面积必须大于 0。
//    2. 如果行数远大于列数，你将如何解答呢？
// https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k

// 思路一：暴力搜索；分别枚举上下边界和左右边界
//         空间复杂度 O(m^2 * n^2) 空间复杂度 O(m^2 * n^2)

// 思路二：根据提示（行数远大于列数）, 枚举左右边界，统计行和；
//         然后在行和数组中找到不超过 K 的最大字序和;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> sums(rows, 0);
        int max_sum = INT_MIN;
        for (int i = 0; i < cols; ++i) {     // 枚举左边界
            // 重置 sums 数组
            fill(sums.begin(), sums.end(), 0);
            for (int j = i; j < cols; ++j) { // 枚举右边界
                for (int k = 0; k < rows; ++k) {
                    sums[k] += matrix[k][j];
                }
                max_sum = max(max_sum, maxSubArraySum(sums, k));
                if (k == max_sum) return k;
            }
        }
        return max_sum;
    }
    // 求解数组 sums 中不超过 k 的最大字序和
    int maxSubArraySum(vector<int>& sums, int k) {
        // 先忽略上界 k，求最大字序和
        int cur_sum = 0, max_sum = INT_MIN;
        for (int& i : sums) {
            if (cur_sum >= 0) {
                cur_sum += i;
            } else {
                cur_sum = i;
            }
            max_sum = max(max_sum, cur_sum);
        }
        // 若最大字序和小于等于 k，直接返回
        if (max_sum <= k) return max_sum;
        // 如果最大字序和大于 k，则枚举左右边界，找到不超过 k 的最大值
        max_sum = INT_MIN;
        for (int i = 0; i < sums.size(); ++i) {
            cur_sum = 0;
            for (int j = i; j < sums.size(); ++j) {
                cur_sum += sums[j];
                if (cur_sum <= k) {
                    max_sum = max(max_sum, cur_sum);
                }
                if (max_sum == k) return k;
            }
        }
        return max_sum;
    }
};
