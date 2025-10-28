class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;

            if(m + 1 >= nums.size())
                return nums[m];
            else if(nums[m + 1] < nums[m])  
                return nums[m + 1];

            if(m - 1 < 0)
                return nums[m];
            else if(nums[m] < nums[m - 1])
                return nums[m];

            if(nums[r] > nums[m])
                r = m;
            else
                l = m + 1;
        }

        return -1;
    }
};