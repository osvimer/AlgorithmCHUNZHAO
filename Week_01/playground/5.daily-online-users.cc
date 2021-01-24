// 请根据某公司的每日在线用户数量列表，重新生成一个列表。
// 新列表中对应位置的输出为：距离下次出现比当前更多的在线用户数所需要等待的天数。
// 如果每日用户在这之后都不会再升高，请用 0 来替代。
// 示例
// 输入：
// [13, 14, 15, 11, 9, 12, 16, 13]
// 输出：
// [1, 1, 4, 2, 1, 1, 0, 0]

// 思路: 这题与“视野总和”类似，可以用单调栈解决。
class Solution {
  public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> result(T.size());
    stack<int> s;
    for (int i = 0; i < T.size(); ++i) {
      if (s.empty() || T[i] < T[s.top()]) {
        s.push(i);
      } else {
        while (!s.empty() && T[i] > T[s.top()]) {
          result[s.top()] = i - s.top();
          s.pop();
        }
        s.push(i);
      }
    }
    return result;
  }
};
