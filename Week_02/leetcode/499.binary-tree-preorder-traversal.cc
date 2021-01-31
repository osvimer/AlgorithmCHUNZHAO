// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

// 思路一: 递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalHelper(result, root);
        return result;
    }

    void preorderTraversalHelper(vector<int>& v, TreeNode* root) {
        if (!root) return;
        v.push_back(root->val);
        preorderTraversalHelper(v, root->left);
        preorderTraversalHelper(v, root->right);
    }
};

// 思路二：迭代，使用辅助栈
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root) st.push(root);
        TreeNode* cur = nullptr;
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        return result;
    }
};