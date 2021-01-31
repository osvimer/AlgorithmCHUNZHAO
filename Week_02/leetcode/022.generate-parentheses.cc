// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
// 示例
// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]

// 思路一：暴力法，相当于 2N 个位置选取 N 个位置放左（右）括号；然后用栈检查合法性；
// 思路二：递归法
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return result;
        helper(0, 0, n, string());
        return result;
    }

    void helper(int left, int right, int max, const string& s) {
        if (left == max && right == max) {
            result.push_back(s);
            return;
        }
        // 剪枝条件一
        if (left < max) {
            helper(left + 1, right, max, s + "(");
        }
        // 剪枝条件二
        if (left > right) {
            helper(left, right + 1, max, s + ")");
        }
    }
private:
    vector<string> result;
};