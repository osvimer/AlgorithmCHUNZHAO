// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
// 示例 1：
//      输入：nums = [1,1,2]
//      输出：
//          [[1,1,2],
//          [1,2,1],
//          [2,1,1]]
// 示例 2：
//      输入：nums = [1,2,3]
//      输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 链接：https://leetcode-cn.com/problems/permutations-ii

// 思路一：在 46 题 “全排列 I” 的基础，加上去重操作；
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<bool> used(sz, false);
        vector<int> v(sz);
        dfs(nums, used, 0, v);
        return result;
    }
    void dfs(vector<int>& nums, vector<bool>& used, int depth, vector<int>& v) {
        if (depth == nums.size()) {
            result.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 去重
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) continue;
            vector<int> t(v);
            t[depth] = nums[i];
            used[i] = true;
            dfs(nums, used, depth+1, t);
            used[i] = false;
        }
    }
private:
    vector<vector<int>> result;
};