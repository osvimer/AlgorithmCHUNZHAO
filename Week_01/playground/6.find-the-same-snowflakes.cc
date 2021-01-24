// 请编写一个程序验证：世界上没有两片雪花是一样的。
// 您的程序将读取有关雪花的信息数据，判断其中是否存在可能相同的一对雪花。
// 每一片雪花都有六只手臂，任何一对具有相同长度手臂的雪花应该被你的程序标记为可能相同。
// 
// 输入一个长度为 n(0 < n ≤ 100000) 的二维数组，表示 n 朵雪花的信息。
// 每行包含六个数表示雪花的手臂长度 (长度至少为 0 且小于 10000000)，这六个数按照
// 雪花顺时针或者逆时针给出，但可以从六个当中的任意一个开始。
// 例如同一片雪花可以描述为 [1,2,3,4,5,6] 或者 [4,3,2,1,6,5]
// 
// 如果所有雪花都是不同的，则程序应打印 No
// 如果有一对可能相同的雪花，程序应该打印 Yes
// 
// 提示: 请尽量不使用时间复杂度为 O(n^2) 的解法
// 
// 示例
// 输入：
// [[1,2,3,4,5,6], [4,3,2,1,6,5]]
// 输出：Yes

class Solution {
  public:
  string findSameSnow(vector<vector<int>>& snows) {
    unordered_map<vector<int>, vector<vecotor<int>>> appeared;
    for (vector<int>& s : snows) {
      vector<int> t = s;
      sort(t.begin(), t.end());
      auto it = appeared.find(t);
      if (appeared.end() == it) {
        appeared[t].push_back(s);
      } else {
        for (vector<int>& v : it->second) {
          if (isSameSnow(s, v)) {
            return "YES";
          }
        }
        appeared[t].push_back(s);
      }
    }
    return "NO";
  }
  
  bool isSameSnow(vector<int>& v1, vector<int>& v2) {
    // TODO
  }
};