// 某公司开发设计了一个名为 X 的数据流管理系统，用以处理对数据流的查询。
// j用户可以在 X 中进行注册查询，X 将保持在不断变化的数据上执行查询，并且按照用户所需要的频率返回结果。

// 具体的指令包括：[queryId, begintime, period]
// queryId 是用户 query（注册查询）的 id（0<id<=3000)，begintime 表示该查询开始执行的时间，
// period(0 秒 <period<=3000 秒) 是两次连续执行查询的间隔。
// 系统中存在多个 query，可以保证每个 query 都有对应的唯一的 queryId，你的任务就是告诉前 K 个查询返回结果。
// 如果两个或多个 query 查询同时返回结果，它们将按照 queryId 的升序逐个返回结果。
// 
// 示例：
// 输入：
// [[2004, 200, 200],
// [2005, 300, 300]]
// 5
// 是一组指令，[2004, 200, 200] 表示 queryID 是 2004，第一次运行是 200s 时候，且每隔 200s 运行一次
// 
// 输出：
// [2004, 2005, 2004, 2004, 2005]
// 
// 解释：
// t = 200 时，执行 2004
// t = 300 时，执行 2005
// t = 400 时，执行 2004
// t = 600 时，执行 2004, 2005（2004 的 id 小于 2005)

// 思路: 使用优先级队列。将每个查询指令从第一次到查询到第 K 次寻查的时间点都插入优先级队列。
//      这样优先级队列的前 K 个元素对应的 ID 就是返回结果。class Solution {
  public:
  vector<int> findTopKQuery(vector<vector<int>>& orders, int k) {
    vector<int> result;
    if (orders.empty() || k <= 0) {
      return result;
    }
    auto cmp = [](pair<int, int>& left, pair<int, int>& right) {
      // 注意: 优先级队列默认使用 std::less 比较器，对应优先级的降序排列；
      //      这里需要的升序排列，所以应使用与 std::greater 等效的比较器。
      if (left.second == right.second) {
        return left.first > right.first;
      } else {
        return left.second > right.second;
      }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
    for (vector<int>& v : orders) {
      for (int i = 0; i < k; ++i) {
        que.push({v[0], v[1] + i * v[2]});
      }
    }
    while (k--) {
      result.push_back(que.top().first);
      que.pop();
    }
    return result;
  }
};