class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(map.contains(sum - k)) {
                res += map[sum - k];
            }
            map[sum]++;
        }

        return res;
    }
};