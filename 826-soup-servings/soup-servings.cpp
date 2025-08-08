class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        
        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1.0));
        return Rec(n, n, memo);
    }

    double Rec(int a, int b, vector<vector<double>>& memo) {
        if (a <= 0 && b > 0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (a > 0 && b <= 0) return 0.0;

        if (memo[a][b] >= 0) return memo[a][b]; // Already computed

        double res = 0;
        res += Rec(max(0, a - 100), max(0, b),      memo);
        res += Rec(max(0, a - 75),  max(0, b - 25), memo);
        res += Rec(max(0, a - 50),  max(0, b - 50), memo);
        res += Rec(max(0, a - 25),  max(0, b - 75), memo);

        return memo[a][b] = 0.25 * res;
    }
};
