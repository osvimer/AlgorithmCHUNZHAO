// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
// 但是，每个孩子最多只能给一块饼干。

// 对每个孩子 i，都有一个胃口值 g[i]，
// 这是能让孩子们满足胃口的饼干的最小尺寸；
// 并且每块饼干 j，都有一个尺寸 s[j] 。
// 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，
// 这个孩子会得到满足。
// 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

// https://leetcode-cn.com/problems/assign-cookies


// 思路：贪心法，每次尽可能用最小的饼干满足胃口最小的孩子
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;
        for (int i = 0; i < s.size() && count < g.size(); i++) {
            if (s[i] >= g[count]) {
                count++;
            }
        }
        return count;
    }
};
