class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        reverse(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); i++) {
            int idx = nums2.end() - lower_bound(nums2.begin(), nums2.end() - i, nums1[i]);
            res = max(idx - i - 1, res);
        }
        
        return res;
    }
};