class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // both dfs and bfs should work here
        vector<vector<int>> graph(n, vector<int>());
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        queue<int> q;
        vector<bool> visited(n);
        visited[source] = true;
        q.push(source);

        while(q.size()) {
            int curr = q.front(); q.pop();

            if (curr == destination) {
                return true;
            }

            for (auto& node : graph[curr]) {
                if (!visited[node]) {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }

        return false;
    }
};