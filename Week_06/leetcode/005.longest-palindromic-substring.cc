// 给你一个字符串 s，找到 s 中最长的回文子串。
// 示例 1：
//    输入：s = "babad"
//    输出："bab"
//    解释："aba" 同样是符合题意的答案。
// 示例 2：
//    输入：s = "cbbd"
//    输出："bb"
// https://leetcode-cn.com/problems/longest-palindromic-substring

// 思路一：动态规划: 枚举左右边界，判断是否是回文字串
//         记录最长回文字串的起始位置和长度
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int left = 0, max_len = 1;
        //dp[i][j]表示以 s[i] 开始以 s[j] 结尾的子串是否是回文字串。
        for (int j = 0; j < s.size(); ++j) {
            dp[j][j] = true;
            for (int i = 0; i < j; ++i) {
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]) || (i == j - 1 && s[i] == s[j]);
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    left = i;
                }
            }
        }
        return s.substr(left, max_len);
    }
};

// 思路二：中心扩散法；中心有单字符扩散和双字符两种情况
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int n = 2 * s.size() - 1;
        int start = 0, max_len = 1;
        for (int i = 1; i < n - 1; ++i) {
            int left = i / 2;
            int right = i % 2 ? left + 1 : left;
            while (s[left] == s[right] && left > 0 && right < s.size()) {
                left--;
                right++;
            }
            if (s[left] != s[right]) {
                left++;
                right--;
            }
            if (left < right && right - left + 1 > max_len) {
                max_len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, max_len);
    }
};
