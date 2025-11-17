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
    void invertTreeRec(TreeNode* node) {
        if(!node)
            return;
        swap(node->left, node->right);
        invertTreeRec(node->left);
        invertTreeRec(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeRec(root);
        return root;   
    }
};