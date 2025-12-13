class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i); // original index
        }

        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq; // {processingTime, index}

        vector<int> result;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                time = max(time, (long long)tasks[i][0]);
            }

            while (i < n && tasks[i][0] <= time) {
                pq.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }

            auto [proc, idx] = pq.top();
            pq.pop();
            time += proc;
            result.push_back(idx);
        }

        return result;
    }
};
