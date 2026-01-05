class Solution {
public:
    // bellman-ford when limiting stops
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<long long> temp = dist;
            for (const auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] == LLONG_MAX) continue;
                temp[v] = min(temp[v], dist[u] + w);
            }
            dist = temp;
        }

        return dist[dst] == LLONG_MAX ? -1 : dist[dst];
    }
};
