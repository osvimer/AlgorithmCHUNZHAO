// 给定一个 N 叉树，返回其节点值的前序遍历。

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
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderHelper(result, root);
        return result;
    }
    void preorderHelper(vector<int>& v, Node* root) {
        if (!root) return;
        v.push_back(root->val);
        for (Node* it : root->children) {
            preorderHelper(v, it);
        }
    }
};