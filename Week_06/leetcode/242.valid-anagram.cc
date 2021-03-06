// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 示例 1:
//    输入: s = "anagram", t = "nagaram"
//    输出: true
//
// 示例 2:
//    输入: s = "rat", t = "car"
//    输出: false
//
// 说明: 你可以假设字符串只包含小写字母。
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
//
// https://leetcode-cn.com/problems/valid-anagram

// 思路一：排序后比较
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 思路二：利用哈希表统计词频
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> frequency;
        for (char c : s) {
            frequency[c]++;
        }
        for (char c : t) {
            frequency[c]--;
        }
        for (auto& p : frequency) {
            if (0 != p.second) {
                return false;
            }
        }
        return true;
    }
};
