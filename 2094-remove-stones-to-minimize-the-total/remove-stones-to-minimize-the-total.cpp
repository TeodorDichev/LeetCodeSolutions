class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end()); // O(n)

        while(k--) { // O(k)
            int curr = pq.top(); pq.pop();
            pq.push(curr - floor(curr / 2.0));
        }

        int sum = 0;
        while(pq.size()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};