class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return climbStairsRec(n, dp);
    }

    int climbStairsRec(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != 0) return dp[n];

        return dp[n] = climbStairsRec(n-1, dp) + climbStairsRec(n-2, dp);
    }
};