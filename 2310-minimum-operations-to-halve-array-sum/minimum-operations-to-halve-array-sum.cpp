class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0); // use 0.0 for double sum
        priority_queue<double> pq(nums.begin(), nums.end());    // use double pq

        double target = sum / 2.0;
        int cnt = 0;

        while (target > 1e-6) {
            double curr = pq.top() / 2.0;
            pq.pop();
            target -= curr;
            pq.push(curr);
            cnt++;
        }

        return cnt;
    }
};
