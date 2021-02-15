// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。
// 你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

// 思路一：贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};

// 思路二：动态规划
// 重复子问题：第 i 天的最大利润
// 状态空间：
//    dp[i][0] 第 i 天不持有股票
//    dp[i][1] 第 i 天持有股票
// 状态转移方程：
//    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
//    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2] = {0, -prices[0]};
        for (int i = 1; i < prices.size(); ++i) {
            int m = dp[0], n = dp[1];
            dp[0] = max(m, n + prices[i]);
            dp[1] = max(n, m - prices[i]);
        }
        return dp[0];
    }
};
