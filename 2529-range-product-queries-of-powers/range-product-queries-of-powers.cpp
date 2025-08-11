class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        int power = 1;
        while (power <= n) power <<= 1;
        power >>= 1;

        vector<int> powers;
        while (n > 0) {
            if (power <= n) {
                powers.push_back(power);
                n -= power;
            }
            power >>= 1;
        }

        int sz = powers.size();
        vector<vector<int>> prefix(sz, vector<int>(sz, 0));
        for (int i = 0; i < sz; i++) {
            prefix[i][i] = powers[sz - 1 - i];
            for (int j = i + 1; j < sz; j++) {
                prefix[i][j] = (1LL * prefix[i][j - 1] * powers[sz - 1 - j]) % MOD;
            }
        }

        vector<int> res(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            res[i] = prefix[queries[i][0]][queries[i][1]];
        }

        return res;
    }
};
