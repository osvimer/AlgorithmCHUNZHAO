// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
// 这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，
// 系统会自动报警 。
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，
// 能够偷窃到的最高金额。
// https://leetcode-cn.com/problems/house-robber-ii

// 思路：在 198题 "house-robber" 的基础上，分别求解从第一间房子偷到倒数第二间房子
//       以及从第二间房子偷到最后一件房子的最大金额，求二者的最大值。
//       注意边界条件检查。
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(maxValue(nums, 0, nums.size() - 2), maxValue(nums, 1, nums.size() - 1));
    }

    int maxValue(vector<int>& nums, int begin, int end) {
        if (begin > end || end < 0) return 0;
        int f0 = 0, f1 = nums[begin], f2 = nums[begin];
        for (int i = begin + 1; i <= end; ++i) {
            f2 = max(f0 + nums[i], f1);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
