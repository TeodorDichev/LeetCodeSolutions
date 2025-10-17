class Solution {
    vector<vector<int>> result;

    void rec(vector<int>& nums, vector<int>& set, int index) {
        if(nums.size() == index) {
            result.push_back(set);
            return;
        }

        set.push_back(nums[index]);
        rec(nums, set, index+1);

        set.pop_back();
        rec(nums, set, index+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> set;
        rec(nums, set ,0);
        return result;
    }
};