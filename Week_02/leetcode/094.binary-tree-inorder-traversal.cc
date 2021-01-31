// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。

// 思路一: 递归解法
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelper(result, root);
        return result;
    }

    void inorderTraversalHelper(vector<int>& v, TreeNode* root) {
        if (!root) return;
        inorderTraversalHelper(v, root->left);
        v.push_back(root->val);
        inorderTraversalHelper(v, root->right);
    }
};

// 思路二: 迭代法，使用辅助栈，每个结点先入栈，当其左子树访问完后，将其加入访问数组
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};