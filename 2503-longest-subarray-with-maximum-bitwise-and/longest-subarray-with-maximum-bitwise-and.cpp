class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int bestLen = 0, currLen = 0;

        for (int num : nums) {
            if (num == maxNum) {
                currLen++;
                bestLen = max(bestLen, currLen);
            } 
            else {
                currLen = 0;
            }
        }

        return bestLen;
    }
};
