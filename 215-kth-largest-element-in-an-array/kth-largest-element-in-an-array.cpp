class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        for (int i = k; i < nums.size(); ++i) {
            pq.push(nums[i]);
            pq.pop();
        }

        return pq.top();
    }
};