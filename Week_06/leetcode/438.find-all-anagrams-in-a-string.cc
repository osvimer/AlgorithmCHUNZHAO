// 给定一个字符串 s 和一个非空字符串 p，
// 找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
// 说明：
// 字母异位词指字母相同，但排列不同的字符串。
// 不考虑答案输出的顺序。
// 示例 1:
//    输入: s: "cbaebabacd" p: "abc"
//    输出: [0, 6]
//    起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
//    起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string

// 思路：滑动窗口 + 词频统计
//       依次比较每个窗口内字串的词频与目标字符串的词频
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size()) return result;
        vector<int> current(26), target(26);
        for (char c : p) {
            target[c - 'a']++;
        }
        for (int i = 0; i < p.size(); ++i) {
            current[s[i] - 'a']++;
        }
        if (current == target) {
            result.push_back(0);
        }
        for (int i = 1; i <= s.size() - p.size(); ++i) {
            current[s[i - 1] - 'a']--;
            current[s[i + p.size() - 1] - 'a']++;
            if (current == target) {
                result.push_back(i);
            }
        }
        return result;
    }
};
