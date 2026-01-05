class Solution {
public:
    // bellman-ford when limiting stops but it is slower
    // djikstra + extra array for stops for better performance
    // int findCheapestPrice(int n, vector<vector<int>>& flights,
    //                       int src, int dst, int k) {
    //     vector<long long> dist(n, LLONG_MAX);
    //     dist[src] = 0;

    //     for (int i = 0; i <= k; i++) {
    //         vector<long long> temp = dist;
    //         for (const auto& f : flights) {
    //             int u = f[0], v = f[1], w = f[2];
    //             if (dist[u] == LLONG_MAX) continue;
    //             temp[v] = min(temp[v], dist[u] + w);
    //         }
    //         dist = temp;
    //     }

    //     return dist[dst] == LLONG_MAX ? -1 : dist[dst];
    // }

    struct Edge {
        int to;
        int weight;
    };

    struct Node {
        int index;
        int stops;
        int cost;

        bool operator<(const Node& other) const {
            return cost > other.cost; // min-heap
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        unordered_map<int, vector<Edge>> graph;
        for (const auto& f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        vector<int> bestCost(n, INT_MAX);
        vector<int> bestStops(n, INT_MAX);

        priority_queue<Node> pq;
        pq.push({src, 0, 0});
        bestCost[src] = 0;
        bestStops[src] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (curr.index == dst) return curr.cost;
            if (curr.stops > k) continue;

            // prune worse states
            if (curr.cost > bestCost[curr.index] && curr.stops > bestStops[curr.index]) continue;

            for (const auto& e : graph[curr.index]) {
                int nextCost = curr.cost + e.weight;
                int nextStops = curr.stops + 1;

                if (nextCost < bestCost[e.to] || nextStops < bestStops[e.to]) {
                    bestCost[e.to] = nextCost;
                    bestStops[e.to] = nextStops;
                    pq.push({e.to, nextStops, nextCost});
                }
            }
        }

        return -1;
    }
};
