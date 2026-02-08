class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[m][k] m tries and k eggs
        // you need only the prev turn
        vector<int> dp(k + 1, 0);
        int m = 0;
        
        while (dp[k] < n) {
            m++;
            // back to front
            for (int j = k; j > 0; j--) {
                dp[j] = dp[j] + dp[j - 1] + 1;
            }
        }
        
        return m;
    }
};