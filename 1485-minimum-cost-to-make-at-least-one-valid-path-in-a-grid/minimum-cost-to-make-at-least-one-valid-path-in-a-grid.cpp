class Solution {
    struct Node {
        int i, j;
        int weight;

        bool operator <(const Node& other) const {
            return weight > other.weight;
        }
    };

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        distances[0][0] = 0;

        priority_queue<Node> nextToProcess;
        nextToProcess.push({0,0,0});

        int cost = 0;
        while (nextToProcess.size()) {
            auto curr = nextToProcess.top();
            nextToProcess.pop();

            if (curr.weight > distances[curr.i][curr.j]) continue;

            vector<tuple<int,int,int>> directions = {{0,1,1},{0,-1,2},{1,0,3},{-1,0,4}};
            for (auto [i, j, a] : directions) {
                int ni = curr.i + i;
                int nj = curr.j + j;
                if (ni >= m || ni < 0 || nj >= n || nj < 0) continue;

                int cost = a == grid[curr.i][curr.j] ? 0 : 1;
                if (curr.weight + cost < distances[ni][nj]) {
                    distances[ni][nj] = curr.weight + cost;
                    nextToProcess.push({ni, nj, curr.weight + cost});
                }
            }

        }

        return distances[m-1][n-1];
    }
};