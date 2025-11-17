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
    void resSearch(vector<int>& res, TreeNode* root) {
        if(root) {
            resSearch(res, root->left);
            res.push_back(root->val);
            resSearch(res, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        resSearch(res, root);
        return res;
    }
};