// 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
// 示例 1：
//    输入："abc"
//    输出：3
//    解释：三个回文子串: "a", "b", "c"
// 示例 2：
//    输入："aaa"
//    输出：6
//    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
// https://leetcode-cn.com/problems/palindromic-substrings

// 思路一：暴力法，双重循环遍历各区间，直接判断每个区间是否为回文字串
//         时间复杂度: O(n^3)
//         空间复杂度：O(1)
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                result += isPalindrome(s, j, i);
            }
        }
        return result;
    }
    bool isPalindrome(string& s, int begin, int end) {
        while (begin < end) {
            if (s[begin++] != s[end--]) {
                return false;
            }
        }
        return s[begin] = s[end];
    }
};

// 思路二，动态规划
// 重复子问题：区间 [i, j] 内的字串是否为回文子串。
// 状态空间: bool dp[i][j]; (false or true)
// 状态转移方程: dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1]));
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        // dp[i][j] 区间[i, j]内的字串是否为回文字串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        // 这样的遍历顺序保证处理 dp[i][j] 时，dp[i+1][j-1] 必然已被赋值
        for (int j = 0; j < s.size(); ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    result++;
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return result;
    }
};

// 思路三：中心扩散法
// 分别以 n 个字符和 n-1 对相邻的字符为中心向外扩散
// 时间复杂度 O(N^2)
// 空间复杂度 O(1)
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int left = i, right = i + 1;
            // 以 s[i] 为中心进行扩散
            while (left >= 0 && right < s.size()) {
                if (s[left--] == s[right++]) {
                    ++result;
                } else {
                    break;
                }
            }
            // 以 s[i] 和 s[i+1] 为中心进行扩散
            left = i, right = i + 1;
            while (left >= 0 && right < s.size()) {
                if (s[left--] == s[right++]) {
                    ++result;
                } else {
                    break;
                }
            }
        }
        return result;
    }
};
