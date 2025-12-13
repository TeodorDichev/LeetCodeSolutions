class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int m1 = pq.top();
            pq.pop();
            int m2 = pq.top();
            pq.pop();
            int diff = abs(m1 - m2);
            if (diff) {
                pq.push(diff);
            }
        }

        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};