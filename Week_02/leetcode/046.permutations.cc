// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
// 示例:
//      输入: [1,2,3]
//      输出:
//      [
//        [1,2,3],
//        [1,3,2],
//        [2,1,3],
//        [2,3,1],
//        [3,1,2],
//        [3,2,1]
//      ]
// 链接：https://leetcode-cn.com/problems/permutations

// 思路一：回溯
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return result;
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
            if (!used[i]) {
                used[i] = true;
                vector<int> t(v);
                t[depth] = nums[i];
                dfs(nums, used, depth+1, t);
                used[i] = false;
            }

        }
    }
private:
    vector<vector<int>> result;
};