// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。
// 设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock


// 思路一：动态规划；
//      重复子问题：第 i 天获得的最大利润（手上持有的现金）
//      定义状态空间: dp[i][0] 为第 i 天不持股时手上现金
//                    dp[i][1] 为第 i 天持股时手上的现金
//      状态转移方程：
//          第 i 天不持股：dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
//          第 i 天持股：  dp[i][1] = max(-prices[i], dp[i-1][1]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        // dp[i][0, 1] 为第 i 天时的手上现金（按是否持股分别计算）
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0; // 不持有股票
        dp[0][1] = -prices[0]; // 持有股票
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(-prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][0];
    }
};

// 思路二：在思路一的基础上，使用循环数组，优化空间复杂度
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        // dp[i][0, 1] 为第 i 天时的手上现金（按是否持股分别计算）
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = 0; // 不持有股票
        dp[0][1] = -prices[0]; // 持有股票
        for (int i = 1; i < prices.size(); ++i) {
            int cur = i % 2;    // 0 or 1
            int pre = cur ^ 1;  // 异或取反; 这里也可写成 pre = !cur;
            dp[cur][0] = max(dp[pre][0], dp[pre][1] + prices[i]);
            dp[cur][1] = max(-prices[i], dp[pre][1]);
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};

// 思路三：一次遍历，记录最低价和最大收益
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        for (int p : prices) {
            if (p < min_price) {
                min_price = p;
            } else {
                max_profit = max(max_profit, p - min_price);
            }
        }
        return max_profit;
    }
};
