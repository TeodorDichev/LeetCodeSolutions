class Solution {
    bool check(vector<int>& nums, int k, int m) {
        int sum = 0, cnt = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > m) {
                cnt++;
                sum = 0;
                continue;
            }
            if(sum + nums[i] <= m) {
                sum += nums[i];
            } else {
                cnt++;
                sum = nums[i];
            }
        }

        return cnt <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while(l <= r) {
            int m = l + (r - l) / 2;
            if(check(nums, k, m))
                r = m - 1;
            else 
                l = m + 1;
        }

        return l;
    }
};