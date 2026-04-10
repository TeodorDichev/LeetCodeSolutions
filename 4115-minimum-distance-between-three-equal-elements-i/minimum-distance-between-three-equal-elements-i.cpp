class Solution {
    int calcDist(int i, int j, int k) {
        return abs(i - j) + abs(j - k) + abs(k - i);
    }

public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        for (auto& kvp : mp) {
            if (kvp.second.size() < 3) {
                continue;
            }

            // sort(kvp.second.begin(), kvp.second.end());
            for (int j = 2; j < kvp.second.size(); j++) {
                minDist = min(minDist, calcDist(kvp.second[j-2], kvp.second[j-1], kvp.second[j]));
            }
        }

        return (minDist == INT_MAX ? -1 : minDist);
    }
};