class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1'000'000'007;

        vector<long long> bits;
        for (int i = 0; n > 0; i++, n >>= 1) {
            if (n & 1) {
                bits.push_back(1LL << i);
            }
        }

        vector<long long> prefix(bits.size());
        prefix[0] = bits[0] % MOD;
        for (int i = 1; i < (int)bits.size(); i++) {
            prefix[i] = (prefix[i - 1] * bits[i]) % MOD;
        }

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product;
            if (l == 0) {
                product = prefix[r];
            } 
            else {
                long long inv = modPow(prefix[l - 1], MOD - 2, MOD);
                product = (prefix[r] * inv) % MOD;
            }
            ans.push_back((int)product);
        }

        return ans;
    }

    long long modPow(long long base, long long exp, int mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};
