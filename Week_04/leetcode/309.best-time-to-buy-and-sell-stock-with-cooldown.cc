// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格
// 设计一个算法计算出最大利润。在满足以下约束条件下，
// 你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 示例:
//      输入: [1,2,3,0,2]
//      输出: 3
//      解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

// 动态规划：冷冻期多加了一个约束条件，前一天如果卖出，当天不得再次买入；
// 定义三种状态：
//    dp[i][0]  第 i 天不持股，且当天未卖出
//    dp[i][1]  第 i 天持股
//    dp[i][2]  第 i 天不持股，且于当天卖出
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = 0;           // 不持股且当天未卖出
        dp[0][1] = -prices[0];  // 持股
        dp[0][2] = 0;           // 不持股且当天卖出
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = dp[i-1][1] + prices[i];
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};

// 优化空间复杂度
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> dp(3, 0);
        dp[0] = 0;           // 不持股且当天未卖出
        dp[1] = -prices[0];  // 持股
        dp[2] = 0;           // 不持股且当天卖出
        for (int i = 1; i < prices.size(); ++i) {
            int dp0 = dp[0], dp1 = dp[1], dp2 = dp[2];
            dp[0] = max(dp0, dp2);
            dp[1] = max(dp1, dp0 - prices[i]);
            dp[2] = dp1 + prices[i];
        }
        return max(dp[0], dp[2]);
    }
};
