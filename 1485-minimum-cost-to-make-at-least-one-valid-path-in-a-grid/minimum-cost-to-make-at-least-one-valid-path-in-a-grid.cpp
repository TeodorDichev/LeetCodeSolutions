class Solution {
    struct Node {
        int i, j;
        int weight;

        bool operator <(const Node& other) const {
            return weight > other.weight;
        }
    };

public:
    // dijkstra
    // int minCost(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
    //     distances[0][0] = 0;

    //     priority_queue<Node> nextToProcess;
    //     nextToProcess.push({0,0,0});

    //     int cost = 0;
    //     while (nextToProcess.size()) {
    //         auto curr = nextToProcess.top();
    //         nextToProcess.pop();

    //         if (curr.weight > distances[curr.i][curr.j]) continue;

    //         vector<tuple<int,int,int>> directions = {{0,1,1},{0,-1,2},{1,0,3},{-1,0,4}};
    //         for (auto [i, j, a] : directions) {
    //             int ni = curr.i + i;
    //             int nj = curr.j + j;
    //             if (ni >= m || ni < 0 || nj >= n || nj < 0) continue;

    //             int cost = a == grid[curr.i][curr.j] ? 0 : 1;
    //             if (curr.weight + cost < distances[ni][nj]) {
    //                 distances[ni][nj] = curr.weight + cost;
    //                 nextToProcess.push({ni, nj, curr.weight + cost});
    //             }
    //         }

    //     }

    //     return distances[m-1][n-1];
    // }

    // 0-1 bfs optimization
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        distances[0][0] = 0;

        deque<Node> dq;
        dq.push_front({0, 0, 0});

        // directions: right=1, left=2, down=3, up=4
        vector<tuple<int,int,int>> directions = {{0,1,1},{0,-1,2},{1,0,3},{-1,0,4}};

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            for (auto [di,dj,a] : directions) {
                int ni = curr.i + di;
                int nj = curr.j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                int cost = (a == grid[curr.i][curr.j]) ? 0 : 1;
                int newWeight = curr.weight + cost;

                if (newWeight < distances[ni][nj]) {
                    distances[ni][nj] = newWeight;
                    if (cost == 0)
                        dq.push_front({ni, nj, newWeight}); // process immediately
                    else
                        dq.push_back({ni, nj, newWeight});  // process later
                }
            }
        }

        return distances[m-1][n-1];
    }
};