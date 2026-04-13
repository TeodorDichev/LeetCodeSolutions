class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int i = start, j = start; i >= 0 || j < nums.size(); i--, j++) {
            if (i >= 0 && nums[i] == target) {
                return abs(i-start);
            } else if (j < nums.size() && nums[j] == target) {
                return abs(j-start);
            }
        }

        return -1;
    }
};