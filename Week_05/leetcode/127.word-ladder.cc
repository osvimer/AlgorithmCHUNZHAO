// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
// 序列中第一个单词是 beginWord 。
// 序列中最后一个单词是 endWord 。
// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典 wordList 中的单词。
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，
// 找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
// https://leetcode-cn.com/problems/word-ladder

// 思路：同 “433 最小基因变化”，采用双向 BFS 求解
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (0 == words.count(endWord)) return 0;
        unordered_set<string> start_visited, end_visited;
        start_visited.insert(beginWord);
        end_visited.insert(endWord);
        queue<string> start_que, end_que;
        start_que.push(beginWord);
        end_que.push(endWord);
        int count = 1;
        while (start_que.size() && end_que.size()) {
            count++;
            if (start_que.size() > end_que.size()) {
                swap(start_que, end_que);
                swap(start_visited, end_visited);
            }

            for (int size = start_que.size(); size > 0; --size) {
                string str = start_que.front();
                start_que.pop();
                // TODO: 从 words 里面移除已处理的单词，可加速搜索
                // 但是 “433” 题，不从 gene bank 中移除，反而更快！
                // 百思不解!
                words.erase(str);
                for (int i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (end_visited.end() != end_visited.find(str)) {
                            return count;
                        } else if (start_visited.end() == start_visited.find(str) && words.end() != words.find(str)) {
                            start_que.push(str);
                            start_visited.insert(str);
                        }
                    }
                    str[i] = old;
                }
            }
        }

        return 0;
    }
};
