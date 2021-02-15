// 给定一个整数数组 nums
// 找到一个具有最大和的连续子数组（子数组最少包含一个元素）
// 返回其最大和。
// 示例 1：
//    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//    输出：6
//    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// https://leetcode-cn.com/problems/maximum-subarray

// 思路一
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

// 思路二
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
