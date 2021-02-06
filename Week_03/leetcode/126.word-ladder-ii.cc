// 单词接龙 II

// 思路：同单词接龙I，使用 BFS，将 queue<string> 换成 queue<vector<string>>, 保存访问路径。
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.end() == words.find(endWord)) return result;
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<vector<string>> que;
        que.push(vector<string>({beginWord}));
        bool found = false;
        while (!que.empty() && !found) {
            for (int sz = que.size(); sz > 0; --sz) {
                vector<string> v = que.front();
                que.pop();
                string str = v.back();
                words.erase(str);
                for (int i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == old) continue;
                        str[i] = c;
                        if (endWord == str) {
                            v.push_back(endWord);
                            result.push_back(v);
                            v.pop_back();
                            found = true;
                        } else if (words.end() != words.find(str) && visited.end() == visited.find(str)) {
                            v.push_back(str);
                            que.push(v);
                            v.pop_back();
                            visited.insert(str);
                        }
                    }
                    str[i] = old;
                }
            }
        }
        return result;
    }
};