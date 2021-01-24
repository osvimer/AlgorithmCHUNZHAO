// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，
// 返回移除后数组的新长度。不要使用额外的数组空间，你必须在原地修改输入数组
// 并在使用 O(1) 额外空间的条件下完成。

// 双指针法: 
//        归档指针 index 从 0 开始计数，index 之前的位置表示已归档；
//        遍历数组中每个元素，如果不等于已归档的最后一个元素，将其归档；
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (auto n : nums) {
            if (index == 0 || nums[index - 1] != n) {
                nums [index++] = n;
            }
        }
        return index;
    }
};