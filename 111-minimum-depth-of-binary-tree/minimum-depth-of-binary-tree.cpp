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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 1, res = 10001;
        if(!root)
            return 0;
            
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto curr = q.front();
                if(!curr->left && !curr->right) {
                    res = min(depth, res);
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                q.pop();
            }
            depth++;
        }

        return res;
    }
};