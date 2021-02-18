// 数字 n 代表生成括号的对数，请你设计一个函数，
// 用于能够生成所有可能的并且有效的括号组合。
// 示例 1：
//    输入：n = 3
//    输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：
//    输入：n = 1
//    输出：["()"]
// https://leetcode-cn.com/problems/generate-parentheses

// DFS
// 1. 只要左括号数小于 N，就可以再添加左括号
// 2. 只要右括号数小于左括号数，就可以加右括号
// 3. 递归终止条件：左右括号树都等于 N
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return result;
        string s;
        s.reserve(2 * n);
        dfs(s, 0, 0, n);
        return result;
    }
    void dfs(const string& s, int left, int right, int n) {
        if (left + right == n<<1) {
            result.push_back(s);
            return;
        }

        if (left < n) {
            dfs(s + '(', left + 1, right, n);
        }

        if (right < left) {
            dfs(s + ')', left, right + 1, n);
        }
    }
private:
    vector<string> result;
};
