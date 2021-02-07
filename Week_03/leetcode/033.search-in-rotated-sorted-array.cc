// 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转
// （例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
// 请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array

// 思路：同 "153.寻找旋转排序数组中的最小值"，先找到旋转数组中的最小值
//       然后以最小值为边界，分别在左右两个区间中实施二分查找。
//       时间复杂度: O(logN)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int mi, lo = 0, hi = sz - 1;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums[hi]) {
                lo = mi + 1;
            } else if (nums[lo] > nums[mi]) {
                hi = mi;
                lo++;
            } else {
                mi = lo;
                break;
            }
        }
        int ret = binarySearch(nums, target, 0, (mi + sz - 1) % sz);
        return (-1 != ret) ? ret : binarySearch(nums, target, mi, sz - 1);
    }

    int binarySearch(vector<int>&nums, int target, int lo, int hi) {
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                hi = m - 1;
            } else if (nums[m] < target) {
                lo = m + 1;
            }
        }
        return -1;
    }
};
