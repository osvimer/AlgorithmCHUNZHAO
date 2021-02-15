// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。
// 相邻的结点在这里指的是下标与上一层结点下标相同或者等于上一层结点下标 + 1 的两个结点。
// 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
// https://leetcode-cn.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        int hight = triangle.size();
        for (int i = hight - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
