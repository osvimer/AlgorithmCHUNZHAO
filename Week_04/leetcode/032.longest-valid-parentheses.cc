// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

// 动态规划
// 子问题：以第 i 个字符结尾的最长有效字串长度。
// 状态转移方程：
// 1. s[i] = '(' => dp[i] = 0;
// 2. s[i] = ')'
//    1) s[i-1] = '('
//         => dp[i] = 2;
//            dp[i] += dp[i - dp[i]]; (仅当 i-dp[i] >= 0)
//    2) s[i-1] = ')' 且 dp[i] > 0;
//         => dp[i] = dp[i -dp[i - 1] - 1] + 2; (仅当 i - dp[i - 1] - 1 >= 0)
//            dp[i] += dp[i - dp[i]]; (仅当 i - dp[i] >= 0)
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) return 0;
        vector<int> dp(s.size(), 0);
        int max_len = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (')' == s[i]) {
                if ('(' == s[i-1]) {
                    dp[i] = 2;
                    if (i >= 2) {
                        dp[i] += dp[i-2];
                    }
                } else if (dp[i-1] > 0) {
                    int t = i - dp[i-1] - 1;
                    if (t >= 0 && s[t] == '(') {
                        dp[i] = dp[i-1] + 2;
                    }
                    if (i - dp[i] >= 0) {
                        dp[i] += dp[i - dp[i]];
                    }
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
