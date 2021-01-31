// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 思路：从头遍历数组，遇到非零元素便将其归档，同时归档指针 +1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 != nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};