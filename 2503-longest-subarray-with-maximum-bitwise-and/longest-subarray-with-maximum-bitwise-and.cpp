class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = nums[0], currLen = 1, bestLen = 1;
        bool flag = true;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (maxNum < nums[i])
            {
                maxNum = nums[i];
                currLen = 1;
                bestLen = 1;
                flag = true;
            }
            else if (maxNum == nums[i])
            {
                if (flag)
                {
                    bestLen++;
                }

                currLen++;

                if(currLen > bestLen)
                {
                    flag = true;
                }
            }
            else
            {
                currLen = 1;
                flag = false;
            }
        }

        return bestLen;
    }
};