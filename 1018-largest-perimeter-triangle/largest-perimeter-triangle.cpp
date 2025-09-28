class Solution {
private:
    static bool comp(int a, int b) {
        return a < b;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        for(int i = nums.size() - 1; i >= 2; --i) {
            if(nums[i] < nums[i-1] + nums[i-2]) {
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }

        return 0;
    }
};