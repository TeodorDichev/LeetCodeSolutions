class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int k = 0; k < i; k++) {
                if (nums[k] < nums[i]) {
                    dp[i] = max(dp[i], dp[k] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
