class Solution {
public:
    double calculateDP(int i, int j, vector<vector<double>>& dp) {
        if (i <= 0 && j <= 0) return 0.5;
        if (i <= 0) return 1.0;
        if (j <= 0) return 0.0;

        if (dp[i][j] >= 0) return dp[i][j]; // already computed

        return dp[i][j] = (
            calculateDP(i - 4, j, dp) +
            calculateDP(i - 3, j - 1, dp) +
            calculateDP(i - 2, j - 2, dp) +
            calculateDP(i - 1, j - 3, dp)
        ) / 4.0;
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0;
        int m = ceil(n / 25.0);

        vector<vector<double>> dp(m + 1, vector<double>(m + 1, -1.0));

        for (int k = 1; k <= m; k++) {
            if (calculateDP(k, k, dp) > 1 - 1e-5) {
                return 1.0;
            }
        }
        return calculateDP(m, m, dp);
    }
};
