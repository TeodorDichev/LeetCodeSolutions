class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums) {
            map[num]++;
        }
        
        int maxCnt = 0;
        int result = 0;
        for(auto& pair : map) {
            if(pair.second > maxCnt) {
                result = pair.second;
                maxCnt = pair.second;
            }
            else if(pair.second == maxCnt) {
                result += pair.second;
            }
        }

        return result;
    }
};