class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        unordered_map<int, vector<int>> map;
        vector<int> answer(m, -1);

        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            auto& v = map[nums[queries[i]]];
            int x = queries[i];
            int pos = lower_bound(v.begin(), v.end(), x) - v.begin();

            int dist = INT_MAX;

            auto upd = [&](int idx) {
                if (idx == x) return;
                int d = abs(idx - x);
                dist = min(dist, min(d, n - d));
            };

            if (pos + 1< v.size()) upd(v[pos + 1]);
            if (pos > 0) upd(v[pos - 1]);

            upd(v.front());
            upd(v.back());

            if (dist != INT_MAX) answer[i] = dist;
        }

        return answer;
    }
};