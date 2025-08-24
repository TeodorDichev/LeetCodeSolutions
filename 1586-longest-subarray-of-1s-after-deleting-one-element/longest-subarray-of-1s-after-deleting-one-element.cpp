class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastZero = -1, maxWindow = 0, start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                start = lastZero + 1;
                lastZero = i ;
            } 

            maxWindow = max(maxWindow, i - start);
        }

        return maxWindow;
    }
};