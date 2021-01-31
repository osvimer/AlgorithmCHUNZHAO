// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出
// 和为目标值 的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// 你可以按任意顺序返回答案。

// 思路一：使用双重循环遍历数组求和，时间复杂度 O(n^2)，空间复杂度 O(1)
// 思路二：使用哈希表存储已遍历过的元素和其下标，只需要遍历数组一遍即可.
//        时间复杂度降至 O(n), 空间复杂度 O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> appeared;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = appeared.find(target - nums[i]);
            if (appeared.end() == it) {
                appeared.insert({nums[i], i});
            } else {
                return vector<int>({it->second, i});
            }
        }
        return vector<int>();
    }
};