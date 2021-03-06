// 以数组 intervals 表示若干个区间的集合，
// 其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回一个不重叠的区间数组，
// 该数组需恰好覆盖输入中的所有区间。
// 示例 1：
//    输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//    输出：[[1,6],[8,10],[15,18]]
//    解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：
//    输入：intervals = [[1,4],[4,5]]
//    输出：[[1,5]]
//    解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
// 提示：
//    1 <= intervals.length <= 104
//    intervals[i].length == 2
//    0 <= starti <= endi <= 104
// https://leetcode-cn.com/problems/merge-intervals

// 思路：将区间集合按起始位置排序
//       然后将依次比较后一个区间的起始位置和前一个区间的结束位置
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), [](auto& i, auto& j) {
            return i[0] < j[0];
        });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
