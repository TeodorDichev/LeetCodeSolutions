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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) 
            return p == q;
        if (p->val != q->val) 
            return false;

        return isSameTree(p->left, q->left) &&
                 isSameTree(p->right, q->right);
    }

    void invertTreeRec(TreeNode* node) {
        if(!node)
            return;
        swap(node->left, node->right);
        invertTreeRec(node->left);
        invertTreeRec(node->right);
    }

    bool isSymmetric(TreeNode* root) {
        invertTreeRec(root->right);
        return isSameTree(root->left, root->right);
    }
};