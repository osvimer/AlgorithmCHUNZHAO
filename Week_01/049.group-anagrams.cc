// 字母异位词分组
// 给定一个字符串数组，将字母异位词组合在一起。
// 字母异位词指字母相同，但排列不同的字符串。
// 示例:
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

//  思路一: 先对每个字符串进行排序；异位词的排序结果都是一样的，
//         这样在 map 中的 key 也就是一样的。然后在 map 中
//         添加相应的 vector。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> appeared;
        for (const string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            appeared[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& it : appeared) {
            result.push_back(it.second);
        }
        return result;
    }
};

// 思路二: 利用每个自然数可以用质数唯一表示这一事实，为 26 个字母
//        分配 26 个质数；对每个字符串求其每位对应的质数的乘积，
//        这样异位词的用质数乘积表示的结果必然相等。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long, vector<string>> appeared;
        int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                          31, 37, 41, 43, 47, 53, 59, 61, 67,
                          71, 73, 79, 83, 89, 97, 101};
        for (const string& s : strs) {
            long t = 1;
            for (const char& c: s) {
                t *= primes[c - 'a'];
            }
            appeared[t].push_back(s);
        }
        vector<vector<string>> result;
        for (auto it : appeared) {
            result.push_back(it.second);
        }
        return result;
    }
};