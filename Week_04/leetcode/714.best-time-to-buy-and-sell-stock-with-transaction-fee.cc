// 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；
// 非负整数 fee 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。
// 如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

// 动态规划
//    重复子问题，第 i 天时获取的最大利润（手头持有最多现金数量）
//    状态空间：dp[i][0] 表示第 i 天不持股；
//              dp[i][1] 表示第 i 天持股
//    状态转移方程:
//                  dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] -fee);
//                  dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;           // 不持股
        dp[0][1] = -prices[0];  // 持股
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[prices.size() - 1][0];
    }
};

// 进一步优化空间复杂度
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2, 0);
        dp[0] = 0;           // 第一天不持股
        dp[1] = -prices[0];  // 第一天持股
        for (int i = 1; i < prices.size(); ++i) {
            int m = dp[0], n = dp[1];
            dp[0] = max(m, n + prices[i] - fee);
            dp[1] = max(m - prices[i], n);
        }
        return dp[0];
    }
};
