class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> numMap;

        numMap[0] = -1;
        int maxLen = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1 ? 1 : -1);

            if (numMap.count(cnt)) {
                maxLen = max(maxLen, i - numMap[cnt]);
            } else {
                numMap[cnt] = i;
            }
        }

        return maxLen;
    }
};