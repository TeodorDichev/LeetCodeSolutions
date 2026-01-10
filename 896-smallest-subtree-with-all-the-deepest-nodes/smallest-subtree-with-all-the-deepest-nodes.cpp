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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* last = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            first = q.front();

            while (sz--) {
                last = q.front();
                q.pop();

                if (last->left)  q.push(last->left);
                if (last->right) q.push(last->right);
            }
        }
        return lcs(root, first->val, last->val);
    }

    TreeNode* lcs(TreeNode* root, int n1, int n2) {
        if (!root) return nullptr;
        if (root->val == n1 || root->val == n2)
            return root;

        TreeNode* left = lcs(root->left, n1, n2);
        TreeNode* right = lcs(root->right, n1, n2);

        if (left && right) return root;
        return left ? left : right;
    }
};
