// 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组
// （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_pro = nums[0], max_pro = nums[0], cur_pro = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mn = min_pro, mx = max_pro;
            max_pro = max(mn * nums[i], max(nums[i], mx * nums[i]));
            min_pro = min(mn * nums[i], min(nums[i], mx * nums[i]));
            cur_pro = max(max_pro, cur_pro);
        }
        return cur_pro;
    }
};
