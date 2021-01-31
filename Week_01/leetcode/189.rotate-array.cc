/**
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 进阶：
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/rotate-array
*/

// 思路一: 使用额外的数组，时间和空间复杂度都是 O(n)
// 思路二: 双翻转法，时间复杂度 O(n)，空间负责度 O(1)
//        先将整个数组翻转，于是后 K 个元素被移到头部；
//        再分别将头部 K 个元素和尾部 N-K 个元素翻转；
// 处理细节：K 要对 N 做取余运算，K 为负数时稍有差异；

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        int n = nums.size();
        k = (k < 0) ? n + k % n : k % n; //可考虑负数情况
        reverse(nums, 0, n); // 翻转整个数组
        reverse(nums, 0, k); // 翻转头部 K 个元素
        reverse(nums, k, n); // 翻转尾部 N-K 个元素
    }
    void reverse(vector<int>& nums, int left, int right) {
        if (nums.empty() || left >= right) return;
        for (int i = 0; i < (right - left) / 2; ++i) {
            swap(nums[left + i], nums[right - i - 1]);
        }
    }
};