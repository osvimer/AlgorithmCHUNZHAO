// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。
//（即逐层地，从左到右访问所有节点）。


// 思路一：DFS
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
        dfs(root, 0);
        return result;
    }
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (result.size() <= depth) result.push_back(vector<int>());
        result[depth].push_back(node->val);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
private:
    vector<vector<int>> result;
};

// 思路二：BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};