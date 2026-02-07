class Solution {
    bool contains(vector<int> v, int x) {
        for (int n : v) {
            if (n == x) {
                return true;
            }
        }

        return false;
    }
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());

        for (int i = 0; i < nums.size(); i++) {
            bool placed = false;
            for (int j = 0; j < res.size(); j++) {
                if (!contains(res[j], nums[i])) {
                    res[j].push_back(nums[i]);
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                res.push_back(vector<int>());
                res[res.size() - 1].push_back(nums[i]);
            }
        }

        return res;
    }
};