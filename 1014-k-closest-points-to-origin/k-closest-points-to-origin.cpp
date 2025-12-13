class Solution {
public:
    struct Comparator {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            int da = a[0]*a[0] + a[1]*a[1];
            int db = b[0]*b[0] + b[1]*b[1];
            return da < db; // max-heap by distance
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

        for (auto& p : points) {
            pq.push(p);
            if (pq.size() > k) {
                pq.pop(); // remove farthest
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
