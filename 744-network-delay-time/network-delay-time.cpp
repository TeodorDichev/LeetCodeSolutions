class Solution {
    struct Edge {
        int to, weight;
    };

    struct Node {
        int index, weight;

        bool operator <(const Node& other) const {
            return weight > other.weight;
        }
    };

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<Edge>> graph;
        for (const auto& time : times) {
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        vector<int> distances(n, INT_MAX);
        distances[k - 1] = 0;

        priority_queue<Node> nextToProcess;
        nextToProcess.push({k - 1, 0});

        while (nextToProcess.size()) {
            auto curr = nextToProcess.top();
            nextToProcess.pop();

            // already found a better path
            if (curr.weight > distances[curr.index]) continue;

            for (const auto& edge : graph[curr.index]) {
                int newWeight = edge.weight + curr.weight;
                if (newWeight < distances[edge.to]) {
                    distances[edge.to] = newWeight;
                    nextToProcess.push({edge.to, newWeight});
                }
            }
        }

        int result = -1;
        for (const auto& dist : distances) {
            result = max(result, dist);
        }
        return result == INT_MAX ? -1 : result;
    }
};