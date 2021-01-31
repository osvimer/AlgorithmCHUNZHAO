// 给定一个 N 叉树，返回其节点值的后序遍历。

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

// 思路一
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderHelper(result, root);
        return result;
    }

    void postorderHelper(vector<int>& v, Node* root) {
        if (!root) return;
        for (Node* it : root->children) {
            postorderHelper(v, it);
        }
        v.push_back(root->val);
    }
};