// 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。
// 其中每个字母表示一种不同种类的任务。
// 任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
// 在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。
//
// 然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，
// 因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
//
// 你需要计算完成所有任务所需要的 最短时间 。
//
// https://leetcode-cn.com/problems/task-scheduler

// 思路：对每种任务分别计数；
// 出现次数最多的任务(可能不止一个), 其次数为 most_task_times
// 出现次数最多的任务，其种类为 most_task_count;
// 准备 n + 1 个桶，种类相同的任务分散到不同的桶中，在桶中的位置尽可能一致
// 并且让出现次数最多的任务尽可能排在前面
// 例如：task = ['A', 'A', 'A', 'B', 'B', 'B', 'C', 'D', 'E'], n = 2
// 可如此安排： A B -
//              A B -
//              A B
// 于是桶的大小为 （most_task_times - 1) * (n + 1) + most_task_count
// 桶的大小可能小于总的任务数量；
// 所要计算的最小时间即为桶的大小和任务总数二者中的最大值。
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> record;
        for (char& t: tasks) {
            record[t]++;
        }
        auto best = max_element(record.begin(), record.end(),
            [](auto i, auto j) { return i.second < j.second; });
        int most_task_times = best->second;
        int most_task_count = 0;
        for (auto& it : record) {
            if (it.second == most_task_times) {
                most_task_count++;
            }
        }
        return max(int(tasks.size()),
            (most_task_times - 1) * (n + 1) + most_task_count);
    }
};
