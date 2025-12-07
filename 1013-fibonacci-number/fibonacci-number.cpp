class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, 0);
        return fibRec(n, dp);
    }

    int fibRec(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        if (dp[n] != 0) {
            return dp[n];
        }

        return dp[n] = fibRec(n-1, dp) + fibRec(n-2, dp);
    }
};