// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
// 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
// 示例 1：
//    输入：nums = [10,9,2,5,3,7,101,18]
//    输出：4
//    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：
//    输入：nums = [0,1,0,3,2,3]
//    输出：4
// 示例 3：
//    输入：nums = [7,7,7,7,7,7,7]
//    输出：1
//
// 提示：
//    1 <= nums.length <= 2500
//    -104 <= nums[i] <= 104
//
// 进阶：
//    你可以设计时间复杂度为 O(n2) 的解决方案吗？
//    你能将算法的时间复杂度降低到 O(n log(n)) 吗?
// https://leetcode-cn.com/problems/longest-increasing-subsequence

// 思路一：动态规划
// 状态空间：dp[i] 是以 nums[i] 为结尾的最长严格递增子序列长度
// 时间复杂度：O(N^2)  空间复杂度：O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        int result = 1;
        for (int j = 1; j < nums.size(); ++j) {
            int max_len = 1;
            for (int i = 0; i < j; ++i) {
                if (nums[j] > nums[i]) {
                    max_len = max(dp[i] + 1, max_len);
                }
            }
            dp[j] = max_len;
            result = max(dp[j], result);
        }
        return result;
    }
};

// 思路二：贪心 + 二分查找
//         dp[i] 是长度为 i 的严格递增子序列中末尾的元素；
//         贪心法：从前到后遍历 nums，保证 dp[i] 最小；
//         最终 i 的最大值就是所求结果
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size() + 1);
        dp[0] = INT_MIN;
        int len = 1;
        dp[len] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp[len]) {
                dp[++len] = nums[i];
            } else {
                // 在 dp 找到小于 nums[i] 的最大元素所对应的下标 (pos)
                int left = 1, right = len - 1, pos = 0;
                while (left <= right) {
                    int mi = (left + right) >> 1;
                    if (dp[mi] < nums[i]) {
                        left = mi + 1;
                        pos = mi;
                    } else {
                        right = mi - 1;
                    }
                }
                // 根据贪心选择性， dp[pos + 1] 应该更新为 nums[i]
                dp[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
