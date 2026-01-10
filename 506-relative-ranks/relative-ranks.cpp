class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int k = 1;
        while (!pq.empty()) {
            auto [s, idx] = pq.top();
            pq.pop();

            if (k == 1) res[idx] = "Gold Medal";
            else if (k == 2) res[idx] = "Silver Medal";
            else if (k == 3) res[idx] = "Bronze Medal";
            else res[idx] = to_string(k);

            k++;
        }
        return res;
    }
};
