// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
// 示例：
// 输入: n = 4, k = 2
// 输出:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v(k);
        helper(n, k, 1, 0, v);
        return result;
    }
    void helper(int n, int k, int begin, int sz, vector<int>& v) {
        if (0 == k) {
            result.push_back(v);
            return;
        }
        for (int i = begin; i <= n - k + 1; ++i) {
            vector<int> t(v);
            t[sz] = i;
            helper(n, k-1, i+1, sz+1, t);
        }
    }
private:
    vector<vector<int>> result;
};