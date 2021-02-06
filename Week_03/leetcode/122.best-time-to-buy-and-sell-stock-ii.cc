// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

// 思路：贪心法，只要后一天价格比前一天高，就将价格差算入收益
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }
};