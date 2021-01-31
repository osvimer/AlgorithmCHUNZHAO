// 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

// 思路一：使用小顶堆来过滤掉 N-K 个元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);
        unordered_map<int, int> frequecy;
        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;
        for (int i : nums) {
            frequecy[i]++;
        }
        for (const auto& it : frequecy) {
            que.push({it.second, it.first});
            if (que.size() > k) {
                que.pop();
            }
        }
        while (--k >= 0) {
            result[k] = que.top().second;
            que.pop();
        }
        return result;
    }
};