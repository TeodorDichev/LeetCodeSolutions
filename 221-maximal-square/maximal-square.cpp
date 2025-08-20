class Solution {
public:
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();

    vector<int> dp(n + 1, 0);
    int maxSquare = 0, prev = 0;

    for (int i = 0; i < m; i++) {
        prev = 0;
        for (int j = 0; j < n; j++) {
            int temp = dp[j+1];

            if (matrix[i][j] == '1') {
                dp[j+1] = 1 + min({dp[j], dp[j+1], prev});
                maxSquare = max(maxSquare, dp[j+1]);
            } 
            else {
                dp[j+1] = 0;
            }

            prev = temp;
        }
    }

    return maxSquare * maxSquare;
    }
};