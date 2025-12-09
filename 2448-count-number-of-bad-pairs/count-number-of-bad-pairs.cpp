class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt = 0;
        long long n = (long long)nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            cnt += map[key];
            map[key]++;
        }

        return n * (n - 1) / 2 - cnt;
    }
};