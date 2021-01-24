// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 思路：使用哈希表记录每个字母出现的词频
//      遍历第一个字符串，哈希表中词频+1
//      遍历第二个字符串，哈希表中词频-1
//      最后看词频哈希表中词频是否都为零
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> appeared;
        for (char c : s) {
            auto it = appeared.find(c);
            if (it == appeared.end()) {
                appeared.insert({c, 1});
            } else {
                (it->second)++;
            }
        }

        for (char c : t) {
            auto it = appeared.find(c);
            if (it == appeared.end()) {
                return false;
            } else {
                (it->second)--;
                if (0 == it->second) {
                    appeared.erase(it);
                }
            }
        }

        return appeared.empty();
    }
};