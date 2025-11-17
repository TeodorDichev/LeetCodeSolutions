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
    void recSearch(vector<int>& res, TreeNode* node) {
        if(node) {
            recSearch(res, node->left);
            recSearch(res, node->right);
            res.push_back(node->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        recSearch(res, root);
        return res;
    }
};