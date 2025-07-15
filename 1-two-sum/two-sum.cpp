class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        int x = target - nums[i];
        auto y = mp.find(x);
        if (y != mp.end()) {
            res.push_back(y->second);
            res.push_back(i);
            return res;
        }
        mp[nums[i]] = i;
    }

    return res;
}

};