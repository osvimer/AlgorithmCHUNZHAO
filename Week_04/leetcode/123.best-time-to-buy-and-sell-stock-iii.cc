// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii

// 思路一：动态规划
// 重复子问题：第 i 天时最大利润 dp[i]（手上现金）
// 状态空间：
//      dp[i][0] 第 i 天时尚未完成任何交易
//      dp[i][1] 第 i 天时已经第一次买入股票
//      dp[i][2] 第 i 天时已经第一次卖出股票
//      dp[i][3] 第 i 天时已经第二次买入股票
//      dp[i][4] 第 i 天时已经第二次卖出股票
// 定义初始值：
//      dp[0][0] = 0;
//      dp[0][1] = -prices[0];
//      dp[0][2] = 0;
//      dp[0][3] = -prices[0];
//      dp[0][4] = 0;
// 状态转移方程：
//      dp[i][0] = dp[i-1][0] = 0; // 常量，这一维状态可以省去；
//      dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
//      dp[i][2] = max(dp[i-1][1] + prices[i], dp[i-1][2]);
//      dp[i][3] = max(dp[i-1][2] - prices[i], dp[i-1][3]);
//      dp[i][4] = max(dp[i-1][3] + prices[i], dp[i-1][4]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy1 = max(-prices[i], buy1);
            sell1 = max(buy1 + prices[i], sell1);
            buy2 = max(sell1 - prices[i], buy2);
            sell2 = max(buy2 + prices[i], sell2);
        }
        return sell2;
    }
};
