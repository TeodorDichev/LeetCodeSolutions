class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == 0) {
                int len = 0;
                while (i < nums.size() && nums[i] == 0) {
                    len++;
                    i++;
                }
                // Gaus formula
                res += 1LL * len * (len + 1) / 2;
            } 
            else {
                i++;
            }
        }

        return res;
    }
};