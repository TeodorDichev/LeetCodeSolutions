class Solution {
    struct Node {
        int i, j;
        int weight;

        bool operator <(const Node& other) const {
            return weight > other.weight;
        }
    };
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        distances[0][0] = 0;

        deque<Node> dq;
        dq.push_front({0, 0, 0});

        // directions: right=1, left=2, down=3, up=4
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            for (auto [di,dj] : directions) {
                int ni = curr.i + di;
                int nj = curr.j + dj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                int newWeight = curr.weight + grid[curr.i][curr.j];
                if (newWeight < distances[ni][nj]) {
                    distances[ni][nj] = newWeight;
                    if (grid[curr.i][curr.j] == 0)
                        dq.push_front({ni, nj, newWeight}); // process immediately
                    else
                        dq.push_back({ni, nj, newWeight});  // process later
                }
            }
        }

        return distances[m-1][n-1];
    }
};