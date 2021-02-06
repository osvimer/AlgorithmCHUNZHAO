// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number

// 思路一：回溯
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;
        map<char, string> keyboard = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string s;
        s.reserve(digits.size());
        helper(keyboard, digits, 0, s);
        return result;
    }
    void helper(map<char, string>& keyboard, const string& digits, int index, string& s) {
        if (index >= digits.size()) {
            result.push_back(string(s));
        }
        for (char c: keyboard[digits[index]]) {
            s.append(1, c);
            helper(keyboard, digits, index+1, s);
            s.erase(index, digits.size() - index);
        }
    }
private:
    vector<string> result;
};