// 一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。
// 假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。
// 例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
// 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
// 现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，
// 请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。
// 注意：
//   1. 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
//   2. 如果一个起始基因序列需要多次变化，那么它每一次变化之后的基因序列都必须是合法的。
//   3. 假定起始基因序列与目标基因序列是不一样的。
// https://leetcode-cn.com/problems/minimum-genetic-mutation

// 双向 BFS: 从头部和尾部同时开始搜索
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        // bank 存为哈希表，提高查询效率
        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (start.size() != end.size() || 0 == bank_set.count(end)) return -1;
        // visited 哈希表记录经过的路径，避免重复搜索
        unordered_set<string> start_visited, end_visited;
        start_visited.insert(start);
        end_visited.insert(end);
        queue<string> start_que, end_que;
        start_que.push(start);
        end_que.push(end);
        int result = 0;

        while (!start_que.empty() && !end_que.empty()) {
            // 每次只处理长度最小的队列
            if (start_que.size() > end_que.size()) {
                swap(start_que, end_que);
                swap(start_visited, end_visited);
            }
            result++;
            for (int k = start_que.size(); k > 0; --k) {
                string str = start_que.front();
                start_que.pop();
                for (int j = 0; j < str.size(); ++j) {
                    char old_char = str[j];
                    for (int i = 0; i < 4; ++i) {
                        if (str[j] != genes[i]) {
                            str[j] = genes[i];
                            if (0 != end_visited.count(str)) {
                                return result++;
                            } else if (0 == start_visited.count(str) && 0 != bank_set.count(str)) {
                                start_visited.insert(str);
                                start_que.push(str);
                            }
                        }
                    }
                    str[j] = old_char;
                }
            }
        }

        return -1;
    }
private:
    char genes[4] = {'A', 'T', 'G', 'C'};
};
