// 给定两个字符串 s 和 t，判断它们是否是同构的。
// 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
// 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
// 不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
// 示例 1:
//    输入：s = "egg", t = "add"
//    输出：true
// 示例 2：
//    输入：s = "foo", t = "bar"
//    输出：false
// 示例 3：
//    输入：s = "paper", t = "title"
//    输出：true
// https://leetcode-cn.com/problems/isomorphic-strings

// 思路一：双哈希表（双射）
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //if (s.empty() || t.empty() || s.size() != t.size()) return false;
        unordered_map<char, char> pairs1, pairs2;
        for (int i = 0; i < s.size(); ++i) {
            if ((pairs1.count(s[i]) && pairs1[s[i]] != t[i]) ||
                (pairs2.count(t[i]) && pairs2[t[i]] != s[i])) {
                return false;
            } else {
                pairs1[s[i]] = t[i];
                pairs2[t[i]] = s[i];
            }
        }
        return true;
    }
};
