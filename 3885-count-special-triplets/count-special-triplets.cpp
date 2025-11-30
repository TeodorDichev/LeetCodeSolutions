class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<long long, long long> left, right;
        for (int x : nums) {
            right[x]++;
        }
        long long ans = 0;
        for (int x : nums) {
            right[x]--;
            long long target = (long long)x * 2;
            long long l = left.count(target) ? left[target] : 0;
            long long r = right.count(target) ? right[target] : 0;
            ans = (ans + (l * r) % MOD) % MOD;
            left[x]++;
        }
        return (int)ans;
    }
};
