class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int p = pow(10, 9) + 7;
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;
            while (idx <= r) {
                nums[idx] = ((long long)nums[idx] * v) % p;
                idx += k;
            }
        }

        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            int next = nums[i];
            prev = prev ^ next;
        }
        
        return prev;
    }
};