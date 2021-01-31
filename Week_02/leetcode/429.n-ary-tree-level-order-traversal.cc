// N 叉树的层序遍历
// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）
// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）

// 思路一: 递归

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        que.push(root);
        levelOrderHelper(result, que);
        return result;
    }
    void levelOrderHelper(vector<vector<int>>& v, queue<Node*>& q) {
        if (q.empty()) return;
        queue<Node*> t;
        vector<int> l;
        while (!q.empty()) {
            Node* root = q.front();
            if (root) {
                l.push_back(root->val);
                for (Node* it : root->children) {
                    t.push(it);
                }
            }
            q.pop();
        }
        if (!l.empty()) {
            v.push_back(l);
        }
        swap(q, t);
        levelOrderHelper(v, q);
    }
};

// 思路二: 迭代法
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            vector<int> vec;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                vec.push_back(node->val);
                que.pop();
                for (Node* it : node->children) {
                    if (it) que.push(it);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};