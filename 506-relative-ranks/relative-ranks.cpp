class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq(score.begin(), score.end());
        vector<string> res(score.size());
        int k = 1;
        while (pq.size()) {
            int s = pq.top();
            pq.pop();

            int index = distance(score.begin(), find(score.begin(), score.end(), s));
            if (k == 1) {
                res[index] = "Gold Medal";
            } else if (k == 2) {
                res[index] = "Silver Medal";
            } else if (k == 3) {
                res[index] = "Bronze Medal";
            } else {
                res[index] = to_string(k);
            }
            k++;
        }

        return res;
    }
};