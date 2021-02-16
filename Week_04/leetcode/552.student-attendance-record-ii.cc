// 给定一个正整数 n，返回长度为 n 的所有可被视为可奖励的出勤记录的数量。
// 答案可能非常大，你只需返回结果mod 109 + 7的值。
// 学生出勤记录是只包含以下三个字符的字符串：
// 'A' : Absent，缺勤
// 'L' : Late，迟到
// 'P' : Present，到场
// 如果记录不包含多于一个'A'（缺勤）或超过两个连续的'L'（迟到），则该记录被视为可奖励的。
// 示例 1:
//    输入: n = 2
//    输出: 8
//    解释: 有8个长度为2的记录将被视为可奖励：
//          "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//          只有"AA"不会被视为可奖励，因为缺勤次数超过一次。
// 注意：n 的值不会超过100000。
// https://leetcode-cn.com/problems/student-attendance-record-ii

// 动态规划三步走
// 一、找重复子问题
//    dp[i] -> 长度为 i 的可奖励记录
// 二、定义状态空间
//    1. 为区分是否已有 ‘A', 增加一个纬度 dp[i][j]
//       j = 0 表示尚无 'A', j = 1 表示已有 'A'
//    2. 为区分末尾 ‘L’ 的数目，再增加一维度 dp[i][j][k]
//       k = 0, 1, 2 表示末尾 ‘L’ 的数目
// 三、状态转移方程
class Solution {
public:
    int checkRecord(int n) {
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(2, vector<long>(3, 0)));
        int mod = 1000000007;
        // 赋初始值
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        dp[1][0][2] = 0;
        dp[1][1][0] = 1;
        dp[1][1][1] = 0;
        dp[1][1][2] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % mod;
            dp[i][0][1] = dp[i-1][0][0];
            dp[i][0][2] = dp[i-1][0][1];
            dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % mod;
            dp[i][1][1] = dp[i-1][1][0];
            dp[i][1][2] = dp[i-1][1][1];
        }
        long result = 0;
        // 最终结果是第 n 层所有状态之和
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                result += dp[n][i][j];
            }
        }
        return result % mod;
    }
};

// 由于第 i 层仅与第 i-1 层状态相关，进一步优化空间复杂度
class Solution {
public:
    int checkRecord(int n) {
        int mod = 1000000007;
        long s00 = 1, s01 = 1, s02 = 0, s10 = 1, s11 = 0, s12 = 0;
        for (int i = 2; i <= n; ++i) {
            long t00 = s00, t01 = s01, t02 = s02, t10 = s10, t11 = s11, t12 = s12;
            s00 = (t00 + t01 + t02) % mod;
            s01 = t00;
            s02 = t01;
            s10 = (t00 + t01 + t02 + t10 + t11 + t12) % mod;
            s11 = t10;
            s12 = t11;
        }
        return (s00 + s01 + s02 + s10 + s11 + s12) % mod;
    }
};
