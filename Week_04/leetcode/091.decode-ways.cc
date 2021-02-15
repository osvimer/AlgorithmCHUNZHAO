// 一条包含字母 A-Z 的消息通过以下映射进行了编码 ：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
// 要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。
// 例如，"111" 可以将 "1" 中的每个 "1" 映射为 "A" ，从而得到 "AAA" ，
// 或者可以将 "11" 和 "1"（分别为 "K" 和 "A" ）映射为 "KA" 。注意，"06" 不能映射为 "F" ，
// 因为 "6" 和 "06" 不同。
//
// 给你一个只含数字的 非空 字符串 num ，请计算并返回 解码 方法的 总数 。
// 题目数据保证答案肯定是一个 32 位 的整数。
//
// https://leetcode-cn.com/problems/decode-ways


// 思路一：DFS，从末尾向前推进 （时间复杂度 O(2^n), 超过题目时间限制）
class Solution {
public:
    int numDecodings(string s) {
        result = 0;
        if (s.empty()) {
            return result;
        }
        dfs(s, s.size() - 1);
        return result;
    }
    void dfs(string& s, int index) {
        if (index < 0) {
            result++;
            return;
        } else if (0 == index) {
            if ('0' != s[0]) {
                result++;
            }
            return;
        } else {
            if ('0' == s[index]) {
                if ('1' == s[index-1] || '2' == s[index-1]) {
                    dfs(s, index - 2);
                }
                return;
            } else if ('1' <= s[index] && s[index] <= '6') {
                if ('1' == s[index-1] || '2' == s[index-1]) {
                    dfs(s, index - 2);
                }
                dfs(s, index - 1);
            } else {
                if ('1' == s[index-1]) {
                    dfs(s, index - 2);
                }
                dfs(s, index - 1);
            }
        }
    }
private:
    int result;
};


// 思路二：动态规划
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || '0' == s[0]) return 0;
        long pre = 1, cur = 1;
        for (int i = 1; i < s.size(); ++i) {
            int temp = cur;
            if ('0' == s[i]) {
                if ('1' == s[i-1] || '2' == s[i-1]) {
                    cur = pre;
                } else {
                    return 0;
                }
            } else if ('1' == s[i-1] || ('1' <= s[i] && s[i] <= '6' && '2' == s[i-1])) {
                cur += pre;
            }
            pre = temp;
        }
        return cur;
    }
};
