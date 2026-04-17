class Solution {
public:
    int getRevNum(int num) {
        int res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }

        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        int res = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums_map.count(nums[i])) {
                res = min(res, i - nums_map[nums[i]]);
            }
            nums_map[getRevNum(nums[i])] = i;
        }

        return (res == nums.size() + 1 ? -1 : res);
    }
};