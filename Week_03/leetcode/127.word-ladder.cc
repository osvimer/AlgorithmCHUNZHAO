// 单词接龙
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
// 是一个按下述规格形成的序列：

// 1. 序列中第一个单词是 beginWord 。
// 2. 序列中最后一个单词是 endWord 。
// 3. 每次转换只能改变一个字母。
// 4. 转换过程中的中间单词必须是字典 wordList 中的单词。
// 5. 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
//    找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
//    如果不存在这样的转换序列，返回 0。

// 示例 1：
//      输入：beginWord = "hit", endWord = "cog", 
//           wordList = ["hot","dot","dog","lot","log","cog"]
//      输出：5
//      解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 
//           返回它的长度 5。
// 示例 2：
//      输入：beginWord = "hit", endWord = "cog", 
//           wordList = ["hot","dot","dog","lot","log"]
//      输出：0
//      解释：endWord "cog" 不在字典中，所以无法进行转换。
//  
// 提示：
//      1. 1 <= beginWord.length <= 10 
 //     2. endWord.length == beginWord.length
//      3. 1 <= wordList.length <= 5000
//      4. wordList[i].length == beginWord.length
//      5. beginWord、endWord 和 wordList[i] 由小写英文字母组成
//      6. beginWord != endWord
//      7. wordList 中的所有字符串 互不相同

// https://leetcode-cn.com/problems/word-ladder

// 思路一：BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.end() == words.find(endWord)) return 0;
        queue<string> que;
        que.push(beginWord);
        unordered_set<string> visited; // 避免陷入死循环
        int count = 1;
        while (!que.empty()) {
            ++count;
            for (int size = que.size(); size > 0; --size) {
                string str = que.front();
                que.pop();
                words.erase(str);
                for (int i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (str == endWord) {
                            return count;
                        } else if (words.end() != words.find(str) && visited.end() == visited.find(str)) {
                            que.push(str);
                            visited.insert(str);
                        }
                    }
                    str[i] = old;
                }
            }
        }
        return 0;
    }
};

// 思路二：双向 BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.end() == words.find(endWord)) return 0;
        unordered_set<string> visited1, visited2;
        visited1.insert(beginWord);
        visited2.insert(endWord);
        queue<string> que1, que2;
        que1.push(beginWord);
        que2.push(endWord);
        int count = 1;
        while (que1.size() && que2.size()) {
            count++;
            // 每次从较小的一端搜索
            if (que1.size() > que2.size()) {
                swap(que1, que2);
                swap(visited1, visited2);
            }

            for (int size = que1.size(); size > 0; --size) {
                string str = que1.front();
                que1.pop();
                words.erase(str);
                for (int i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (visited2.end() != visited2.find(str)) {
                            return count;
                        } else if (visited1.end() == visited1.find(str) && words.end() != words.find(str)) {
                            que1.push(str);
                            visited1.insert(str);
                        }
                    }
                    str[i] = old;
                }
            }
        }
        return 0;
    }
};