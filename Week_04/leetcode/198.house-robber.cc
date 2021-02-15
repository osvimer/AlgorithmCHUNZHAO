// 你是一个专业的小偷，计划偷窃沿街的房屋。
// 每间房内都藏有一定的现金，影响你偷窃的
// 唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，
// 计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
// https://leetcode-cn.com/problems/house-robber

// 思路一：动态规划，dp[i] 为偷到第 i 个房子时能偷到的最高金额
//         第 i 个房子可抢可不抢。
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[nums.size()];
    }
};

// 思路二：在思路一的基础上，优化空间复杂度
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int f0 = 0, f1 = nums[0], f2 = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            f2 = max(f0 + nums[i - 1], f1);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
