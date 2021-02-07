// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。
// 请找出其中最小的元素。
// 示例 1：
//    输入：nums = [3,4,5,1,2]
// 输出：1
//    链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array

// 思路：利用二分法找到异常区间，最终边界就是最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums[hi]) {
                lo = mi + 1;
            } else if (nums[lo] > nums[mi]) {
                hi = mi;
                lo = lo + 1;
            } else {
                mi = lo;
                break;
            }
        }
        return nums[mi];
    }
};
