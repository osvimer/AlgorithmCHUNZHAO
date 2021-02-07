// 给定一个非负整数数组，最初位于数组的第一个位置。
// 数组中的每个元素代表在该位置可以跳跃的最大长度。
// 目标是使用最少的跳跃次数到达数组的最后一个位置。
// https://leetcode-cn.com/problems/jump-game-ii

// 思路一: BFS (超时), 有向无权图最短路径
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        queue<int> que;
        que.push(0);
        int last = nums.size() - 1;
        int step = 0;
        while (!que.empty()) {
            step++;
            for (int sz = que.size(); sz > 0; --sz) {
                int pos = que.front();
                int maxStep = nums[pos];
                que.pop();
                for (int i = 1; i <= maxStep; ++i) {
                    if (i + pos >= last) {
                        return step;
                    } else {
                        que.push(pos + i);
                    }
                }
            }
        }
        return -1;
    }
};

// 思路二: 贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, maxPos = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                step++;
                end = maxPos;
            }
        }
        return step;
    }
};
