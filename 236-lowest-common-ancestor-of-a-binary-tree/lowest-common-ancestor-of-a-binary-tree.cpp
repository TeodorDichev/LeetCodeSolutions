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
    bool hasDescendent(TreeNode* node, TreeNode* desc) {
        if(node) {
            if(node->val == desc->val) {
                return true;
            }
            
            return hasDescendent(node->left, desc) || hasDescendent(node->right, desc);
        }

        return false;
    }

    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node) {
            if(hasDescendent(node->left, p) && hasDescendent(node->left, q)) {
                return dfs(node->left, p, q);
            }
            else if(hasDescendent(node->right, p) && hasDescendent(node->right, q)) {
                return dfs(node->right, p, q);
            }
            else {
                return node;
            }
        }

        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};