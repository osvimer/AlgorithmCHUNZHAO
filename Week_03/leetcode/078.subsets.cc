// 给你一个整数数组 nums ，数组中的元素互不相同。
// 返回该数组所有可能的子集（幂集）。
// 解集不能包含重复的子集。你可以按任意顺序返回解集。
// 示例 1：
//      输入：nums = [1,2,3]
//      输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 示例 2：
//      输入：nums = [0]
//      输出：[[],[0]]
// 链接：https://leetcode-cn.com/problems/subsets

// 思路一：回溯
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, 0, v);
        return result;
    }
    void dfs(vector<int>& nums, int index, vector<int>& v) {
        if (index == nums.size()) {
            result.push_back(v);
            return;
        }
        dfs(nums, index + 1, v);
        vector<int> t(v);
        t.push_back(nums[index]);
        dfs(nums, index + 1, t);
    }
private:
    vector<vector<int>> result;
};