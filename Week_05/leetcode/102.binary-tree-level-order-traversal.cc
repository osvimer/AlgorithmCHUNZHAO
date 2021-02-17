// 给你一个二叉树，请你返回其按层序遍历得到的节点值。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> v;
            for (int i = que.size(); i > 0; --i) {
                TreeNode* node = que.front();
                que.pop();
                v.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(v);
        }
        return result;
    }
};
