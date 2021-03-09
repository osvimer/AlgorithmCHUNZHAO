// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符
// 相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
// 题目数据保证答案符合 32 位带符号整数范围。
// 示例 1：
//    输入：s = "rabbbit", t = "rabbit"
//    输出：3
//    解释：如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//          (上箭头符号 ^ 表示选取的字母)
//    rabbbit
//    ^^^^ ^^
//    rabbbit
//    ^^ ^^^^
//    rabbbit
//    ^^^ ^^^
// https://leetcode-cn.com/problems/distinct-subsequences

// 思路：动态规划
//    状态空间：dp[i][j]  表示 s(0, i) 的子序列中 t(0, j) 出现的个数
//    状态转移方程：
//    1. 当 s[i-1] == t[j-1]
//       不包含 s[i-1] 的子序列中 t(0, j) 出现的个数为 dp[i-1][j-1]
//       包含 d[i-1] 的子序列中 t(0, j) 出现的个数为 dp[i-1][j];
//       因此：dp[i][j] = dp[i-1][j] + dp[i-1[j-1]
//    2. 当 s[i-1] != t[j-1] 时： dp[i][j] = dp[i-1][j]
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return 0;
        vector<vector<long>> dp(s.size() + 1, vector<long>(t.size() + 1, 0));
        // s(0, j) 子序列中空串是唯一的，所以 dp[i][0] 需要初始化为 1
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (j > i) continue;
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

// d[i][j] 的值只与上一层的 dp[i-1][j-1], dp[i-1][j] 有关，满足无后效性
// 进一步优化空间复杂度:
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return 0;
        vector<long> dp(t.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            int pre = 1;
            for (int j = 1; j <= t.size(); ++j) {
                if (j > i) break;
                int next_pre = dp[j];
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += pre;
                }
                pre = next_pre;
            }
        }
        return dp[t.size()];
    }
};
