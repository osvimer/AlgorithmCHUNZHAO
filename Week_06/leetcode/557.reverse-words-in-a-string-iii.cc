// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
// 示例：
//    输入："Let's take LeetCode contest"
//    输出："s'teL ekat edoCteeL tsetnoc"
// 提示：
//    在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
// https://leetcode-cn.com/problems/reverse-words-in-a-string-iii

// 思路：双指针，分别找到每个单词的起始位置，然后对每个单词进行反转
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        while (right < s.size()) {
            while (s[right] != ' ' && right < s.size()) {
                right++;
            }
            int next = right + 1;
            --right;
            while (left < right) {
                swap(s[left++], s[right--]);
            }
            left = next;
            right = next;
        }
        return s;
    }
};
