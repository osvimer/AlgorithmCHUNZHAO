// 有 n 个人站队，所有的人全部向右看，个子高的可以看到个子低的发型，
// 给出每个人的身高，问所有人能看到其他人的发型的总和是多少。

// 思路一: 单调栈。当前元素比栈顶元素小，则将当前元素入栈；
//        当前元素比栈顶元素大，则持续进行出栈操作并更新总和，
//        直到栈顶元素大于当前元素；最后将当前元素入栈。
//        参考: https://tronwei.top/2020/05/29/leetcode-22
class Solution {
  public:
  int fieldSum(vector<int>& v) {
    v.push_back(INT_MAX); //确保最后一个元素能够顺利出栈。
    int result = 0;
    stack<int> s;
    for (int i = 0; i < v.size(); ++i) {
      if (s.empty() || v[i] <= v[s.top()]) {
        s.push(i);
      } else {
        while (!s.empty() && v[i] >= v[s.top()]) {
          result += i - s.top() - 1; //这里需要多减一个 1
          s.pop();
        }
        s.push(i);
      }
    }
    return result;
  }
};