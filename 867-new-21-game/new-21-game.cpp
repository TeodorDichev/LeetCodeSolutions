class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || k + maxPts <= n) return 1.0;

        vector<double> dp(n + 1, 0.0);
        double windowSum = 0.0;

        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }

        for (int i = k; i <= min(n, k + maxPts - 1); i++) {
            windowSum += dp[i];
        }

        for (int i = k - 1; i >= 0; i--) {
            dp[i] = windowSum / maxPts;
            windowSum += dp[i];
            if (i + maxPts <= n) {
                windowSum -= dp[i + maxPts];
            }
        }

        return dp[0];
    }
};