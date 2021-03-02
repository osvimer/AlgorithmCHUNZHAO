// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
// 示例：
//     s = "leetcode"      返回 0
//     s = "loveleetcode"  返回 2
// 提示：你可以假定该字符串只包含小写字母。
// https://leetcode-cn.com/problems/first-unique-character-in-a-string

// 思路一：使用哈希表统计每个字符的频率，再从头到尾遍历找出第一个频率为 1 的字符
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> frequency;
        for (char c : s) {
            frequency[c]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
