// 一条基因序列由一个带有8个字符的字符串表示，
// 其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

// 假设我们要调查一个基因序列的变化。一次基因变化意味着
// 这个基因序列中的一个字符发生了变化。
// 例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
// 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
// 现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，
// 请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。
// 如果无法实现目标变化，请返回 -1。

// 注意：
// 1. 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
// 2. 如果一个起始基因序列需要多次变化，那么它每一次变化之后的基因序列都必须是合法的。
// 3. 假定起始基因序列与目标基因序列是不一样的。

// https://leetcode-cn.com/problems/minimum-genetic-mutation

// 思路：BFS
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        set<string> bank_set(bank.begin(), bank.end());
        if (start.size() != end.size() || bank_set.end() == bank_set.find(end)) return -1;
        queue<string> que;
        que.push(start);
        vector<char> gens({'A', 'T', 'G', 'C'});
        int step = 0;
        while (!que.empty()) {
            ++step;
            for (int size = que.size(); size > 0; --size) {
                string str = que.front();
                que.pop();
                bank_set.erase(str);
                for (int i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (int j = 0; j < 4; ++j) {
                        str[i] = gens[j];
                        if (end == str) {
                            return step;
                        } else if (bank_set.end() != bank_set.find(str)) {
                            que.push(str);
                        }
                    }
                    str[i] = old;
                }
            }
        }
        return -1;
    }
};