class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int t = 0; true; t++) {
            if(grid[0][0] <= t) {
                vector<vector<bool>> visited(n, vector<bool>(n, false));
                dfs(grid, visited, n, t, 0, 0);
                if(visited[n-1][n-1]) {
                    return t;
                }
            }
        }

        // unreachable
        return -1;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int t, int i, int j) {
        visited[i][j] = true;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto [dr, dc] : dirs) {
            int nr = i + dr, nc = j + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (visited[nr][nc]) continue;
            if (grid[nr][nc] > t) continue;
            dfs(grid, visited, n, t, nr, nc);
        }
    }
};