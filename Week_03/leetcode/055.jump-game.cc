// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标。
// 示例 1：
// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
// https://leetcode-cn.com/problems/jump-game

// 思路一：贪心法，从最后一格往前推; 更新可达位置，看是否能达第一个下标
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        for (int i = last - 1; i >= 0; --i) {
            if (nums[i] + i >= last) {
                last = i;
            }
        }
        return last == 0;
    }
};
