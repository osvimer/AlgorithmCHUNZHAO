// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv

// 思路一：类比第 122 题，采用动态规划求解
// 第 i 天有 2k+1 种状态，分别对应第 k 笔交易是否完成, 用 dp[i][j] 表示
// 第 i 天的状态 j 只与第 i-1 天的状态 j-1 和 状态 j 有关
// 状态转移方程
// 1. 当 j 为奇数: dp[i][j] = max(dp[i-1][j-1] + prices[i], dp[i-1][j]);
// 2. 当 j 为偶数: dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j]);
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || 0 == k) return 0;
        int n = 2 * k;
        vector<vector<int>> dp(prices.size(), vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = i % 2 ? 0 : -prices[0];
        }
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(-prices[i], dp[i-1][0]);
            for (int j = 1; j < n; ++j) {
                if (j % 2) {
                    dp[i][j] = max(dp[i-1][j-1] + prices[i], dp[i-1][j]);
                } else {
                    dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j]);
                }
            }
        }
        return dp[prices.size() - 1][n - 1];
    }
};

// 类比第 122 题，进一步优化空间复杂度
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || 0 == k) return 0;
        int n = 2 * k;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = i % 2 ? 0 : -prices[0];
        }
        for (int i = 1; i < prices.size(); ++i) {
            dp[0] = max(-prices[i], dp[0]);
            for (int j = 1; j < n; ++j) {
                if (j % 2) {
                    dp[j] = max(dp[j-1] + prices[i], dp[j]);
                } else {
                    dp[j] = max(dp[j-1] - prices[i], dp[j]);
                }
            }
        }
        return dp[n - 1];
    }
};
