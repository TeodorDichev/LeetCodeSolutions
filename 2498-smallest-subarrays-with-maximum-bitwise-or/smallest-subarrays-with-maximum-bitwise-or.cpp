class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n = nums.size();
        vector<int> last(32,-1);
        vector<int> res(n);

        for(int i = n - 1; i >= 0; i--) {
            for(int b = 0; b < 32; b++)
                if(nums[i] & (1 << b))
                    last[b] = i;
           
            int  r = i;
            for(int b = 0; b < 32; b++)
                if(last[b] != -1)
                    r = max(r, last[b]);
            
            res[i] = r - i + 1;
        }

        return res;
    }
};