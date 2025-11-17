class Solution {
public:
    void rangeSumBSTRes(TreeNode* root, int low, int high, int& sum) {
        if (!root) return;

        if (root->val >= low && root->val <= high)
            sum += root->val;

        if (root->val > low)
            rangeSumBSTRes(root->left, low, high, sum);
        if (root->val < high)
            rangeSumBSTRes(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        rangeSumBSTRes(root, low, high, sum);
        return sum;
    }
};
