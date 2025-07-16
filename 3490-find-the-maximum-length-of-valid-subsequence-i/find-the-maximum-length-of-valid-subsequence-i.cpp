class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int cnt1 = 0, cnt2 = 0, cnt3 = 1;
        
        // non-alternating
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                cnt1++; // even
            }
            else {
                cnt2++; //odd
            }
        }

        // alternating
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i-1] % 2 != nums[i] % 2) {
                cnt3++;
            }
        }

        return max({cnt1, cnt2, cnt3});
    }
};
