class Solution {
    struct Node {
        int i, j, time;

        bool operator < (const Node& other) const {
            return time > other.time; // min-heap
        }
    };

public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // early impossible case
        if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<Node> pq;
        pq.push({0, 0, 0});

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!pq.empty()) {
            auto [i, j, t] = pq.top();
            pq.pop();

            if (t > dist[i][j]) continue;
            if (i == m - 1 && j == n - 1) return t;

            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;

                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                int nt = max(t + 1, grid[ni][nj]);

                // parity fix
                // basically can wait here A->B->A
                // never true if nt = t + 1
                if ((nt - t) % 2 == 0) nt++;

                if (nt < dist[ni][nj]) {
                    dist[ni][nj] = nt;
                    pq.push({ni, nj, nt});
                }
            }
        }

        return -1;
    }
};
