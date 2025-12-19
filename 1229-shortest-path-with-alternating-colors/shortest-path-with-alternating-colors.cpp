class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        // color: 0 = red, 1 = blue

        for (auto& e : redEdges)
            graph[e[0]].push_back({e[1], 0});

        for (auto& e : blueEdges)
            graph[e[0]].push_back({e[1], 1});

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(2, INF));
        queue<pair<int,int>> q; // {node, lastColor}

        // start with both colors allowed
        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [u, last] = q.front(); q.pop();

            for (auto [v, color] : graph[u]) {
                if (color != last && dist[v][color] == INF) {
                    dist[v][color] = dist[u][last] + 1;
                    q.push({v, color});
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            ans[i] = (best == INF ? -1 : best);
        }
        return ans;
    }
};
