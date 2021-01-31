// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

// 思路一: 动态规划；从左向右编列，找出每列左边的最大高度，记录到数组 max_left;
//        然后从右往左遍历，找出每列右边的最大高度，记录到数组 max_right;
//        再从左向右遍历每一列，对于第 i 列，计算 max_left[i] 与 max_right[i]
//        其中的较小值 min，若 min 大于 height[i]，改列积水高度为 min-height[i]
//        否则改列没有积水。
//        状态转移方程:
//           max_left[i] = max(max_left[i-1], height[i-1])
//           max_right[i] = max(max_right[right+1], height[right+1])
// 思路二: 双指针法；参考题解 https://cutt.ly/7jBHdMc
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int max_left = 0;
        int max_right = 0;
        int left = 1;
        int right = height.size() - 2;
        int sum = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            if (height[left - 1] < height[right + 1]) {
                max_left = max(max_left, height[left - 1]);
                if (max_left > height[left]) {
                    sum += max_left - height[left];
                }
                ++left;
            } else {
                max_right = max(max_right, height[right + 1]);
                if (max_right > height[right]) {
                    sum += max_right - height[right];
                }
                --right;
            }
        }
        return sum;
    }
};