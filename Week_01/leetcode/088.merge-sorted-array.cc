// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
// 你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

// 思路： 从后向前分别遍历 num1 和 num2，并注意边界检查。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (0 == n) return; // 优化操作：当 nums2 为空，跳过遍历 nums1
        nums1.resize(m + n);
        int i = m + n - 1;
        while (m > 0 && n > 0 && i >= 0) {
            nums1[i--] = (nums1[m-1] > nums2[n-1]) ? nums1[--m]: nums2[--n];
        }
        while (n > 0 && i >= 0) {
            nums1[i--] = nums2[--n];
        }
    }
};