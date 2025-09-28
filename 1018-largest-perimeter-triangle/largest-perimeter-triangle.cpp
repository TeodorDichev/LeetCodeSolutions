class Solution {
private:
    static bool comp(int a, int b) {
        return a < b;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        int res = 0;
        for(int i = nums.size() - 1; i >= 2; --i) {
            int per = nums[i] + nums[i-1] + nums[i-2];
            if(nums[i] < nums[i-1] + nums[i-2] && per > res) {
                res = per;
            }
        }

        return res;
    }
};