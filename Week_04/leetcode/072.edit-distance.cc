// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
// 示例 1：
//    输入：word1 = "horse", word2 = "ros"
//    输出：3
//    解释：
//          horse -> rorse (将 'h' 替换为 'r')
//          rorse -> rose (删除 'r')
//          rose -> ros (删除 'e')
// https://leetcode-cn.com/problems/edit-distance

// 动态规划
// dp[i][j] 表示 word1[0:i] 到 word2[0:j] 的编辑距离
// 状态转移方程：
// 1. word1[i] == word[j]: dp[i][j] = dp[i-1][j-1]
// 2. word1[i] != word[j]: dp = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
//    其中，dp[i-1][j-1] 表示替换（word1[i] 替换为 word2[j])
//          dp[i-1][j]   表示删除 (删除 word1[i])
//          dp[i][j-1]   表示插入 (插入 word2[j])
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

// 进一步优化空间复杂度
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }
        int north_west = 0;
        for (int i = 1; i <= m; ++i) {
            dp[0] = i;
            north_west = i - 1;
            for (int j = 1; j <= n; ++j) {
                int next_north_west = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = north_west;
                } else {
                    dp[j] = min(min(dp[j], dp[j-1]), north_west) + 1;
                }
                north_west = next_north_west;
            }
        }
        return dp[n];
    }
};
