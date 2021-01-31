// 根据一棵树的前序遍历与中序遍历构造二叉树。
// 注意: 你可以假设树中没有重复的元素。

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        return buildTreeHelper(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int p_begin, int p_end, int i_begin, int i_end) {
        if (p_begin == p_end) return nullptr;
        int value = preorder[p_begin];
        int i_root = i_begin;
        while (i_root < i_end) {
            if (value == inorder[i_root]) {
                break;
            }
            i_root++;
        }
        int left_size = i_root - i_begin;
        TreeNode* root = new TreeNode(value);
        root->left = buildTreeHelper(preorder, inorder, p_begin+1, p_begin+1+left_size, i_begin, i_root);
        root->right = buildTreeHelper(preorder, inorder, p_begin+left_size+1, p_end, i_root + 1, i_end);
        return root;
    }
};