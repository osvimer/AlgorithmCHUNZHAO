// 给定一个整数数组 nums
// 找到一个具有最大和的连续子数组（子数组最少包含一个元素）
// 返回其最大和。
// 示例 1：
//    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//    输出：6
//    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// https://leetcode-cn.com/problems/maximum-subarray

// 思路一: 当前和大于零就继续累加
//         当前和小于零就重新累加
//         不断更新字序和的最大值
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0, max_sum = nums[0];
        for (int& i : nums) {
            if (cur_sum >= 0) {
                cur_sum += i;
            } else {
                cur_sum = i;
            }
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
    }
};

// 思路二: 动态规划
// dp[i] 表示以第 i 个数结尾的最大连续子序列之和
// 状态转移方程: dp[i] = max(dp[i-1], 0) + nums[i];
// 解决原始问题：result = dp 数组中的最大值
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] += max(dp[i-1], 0);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
