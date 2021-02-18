// 有 n 个城市，其中一些彼此相连，另一些没有相连。
// 如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
// 那么城市 a 与城市 c 间接相连。
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
// 给你一个 n x n 的矩阵 isConnected ，
// 其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
// 而 isConnected[i][j] = 0 表示二者不直接相连。
// 返回矩阵中 省份 的数量。
// 链接：https://leetcode-cn.com/problems/number-of-provinces

// 思路：使用并查集；若身份 i 和 j 相邻，将其进行 merge 操作
//       最后返回并查集的数目即可
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf(isConnected.size());
        // 这里是个无向图的邻接矩阵, 是对称矩阵，因此查找一般即可
        for (int j = 0; j < isConnected.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.count();
    }
private:
    class UnionFind {
    public:
        UnionFind(int n) : count_(n) {
            parent_.reserve(n);
            for (int i = 0; i < n; ++i) {
                parent_[i] = i;
            }
        }

        int find(int node) {
            while (node != parent_[node]) {
                parent_[node] = parent_[parent_[node]];
                node = parent_[node];
            }
            return node;
        }

        void merge(int p, int q) {
            int root_p = find(p);
            int root_q = find(q);
            if (root_p != root_q) {
                parent_[root_q] = root_p;
                count_--;
            }
        }

        int count() {
            return count_;
        }
    private:
        vector<int> parent_;
        int count_;
    };
};
