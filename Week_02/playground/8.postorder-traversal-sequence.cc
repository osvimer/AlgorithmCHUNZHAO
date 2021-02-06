// 二叉搜索树的后序遍历序列
// 给定一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
// 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
// 提示: 数组长度 <= 1000
// 示例:
//     输入：  [4, 8, 6, 12, 16, 14, 10]
//     输出：  true

class Solution {
  public:
  bool verifyPostorder(vector<int>& postorder) {
    return helper(postorder, 0, postorder.size() - 1);
  }
  bool helper(vector<int>& postorder, int begin, int end) {
    if (begin >= end) return true;
    int root = postorder[end];
    int split = begin;
    while (postorder[split] < root) split++;
    for (int i = split; i < end; ++i) {
      if (postorder[i] < root) return false;
    }
    return helper(postorder, begin, split-1) && helper(postorder, split, end-1);
  }
};