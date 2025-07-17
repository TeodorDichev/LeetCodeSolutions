class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
    int longest = 0;
    std::vector<int> dp(k);

    for (int val = 0; val < k; ++val) {
        std::fill(dp.begin(), dp.end(), 0);

        for (int x : nums) {
            int m = x % k;
            int want = (val - m + k) % k;
            dp[m] = std::max(dp[m], dp[want] + 1);
            longest = std::max(longest, dp[m]);
        }
    }

    return longest;
    }
};