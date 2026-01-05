class Solution {
    struct Edge {
        int to;
        double weight;
    };

    struct Node {
        int index;
        double weight;

        bool operator <(const Node& other) const {
            // looking for max probability so the sign stays the same
            return weight < other.weight;
        }
    };

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<Edge>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        vector<double> probabilities(n, 0.0);
        probabilities[start_node] = 1.0;

        priority_queue<Node> nextToProcess;
        nextToProcess.push({start_node, 1.0});

        while (nextToProcess.size()) {
            auto curr = nextToProcess.top();
            nextToProcess.pop();

            // better probability was already found
            if (curr.weight > probabilities[curr.index]) continue;

            for (const auto& edge : graph[curr.index]) {
                double newProbability = curr.weight * edge.weight;
                if (newProbability > probabilities[edge.to]) {
                    probabilities[edge.to] = newProbability;
                    nextToProcess.push({edge.to, newProbability});
                }
            }
        }

        return probabilities[end_node];
    }
};