class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            bool first = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    first = false;
                    break;
                }
            }

            bool second = true;
            for (int m = i + k; m < i + 2 * k - 1; m++) {
                if (nums[m] >= nums[m + 1]) {
                    second = false;
                    break;
                }
            }

            if (first && second) return true;
        }

        return false;
    }
};
