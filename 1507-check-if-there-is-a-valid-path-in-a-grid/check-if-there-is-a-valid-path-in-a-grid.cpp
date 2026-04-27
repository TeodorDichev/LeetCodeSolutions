class Solution {
    vector<pair<int, int>> calcNextPos(int i, int j, int x) {
        vector<pair<int, int>> res;
        switch (x) {
            case 1:
                res.push_back({i, j + 1});
                res.push_back({i, j - 1});
            break;
            case 2:
                res.push_back({i + 1, j});
                res.push_back({i - 1, j});
            break;
            case 3:
                res.push_back({i, j - 1});
                res.push_back({i + 1, j});
            break;
            case 4:
                res.push_back({i, j + 1});
                res.push_back({i + 1, j});
            break;
            case 5:
                res.push_back({i - 1, j});
                res.push_back({i, j - 1});
            break;
            case 6:
                res.push_back({i - 1, j});
                res.push_back({i, j + 1});
            break;
        }

        return res;
    }

    bool isPosValid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    bool isConnected(int x, int y, int i, int j, vector<vector<int>>& grid) {
        for (auto [x1, y1] : calcNextPos(x, y, grid[x][y])) { 
            if (x1 == i && y1 == j) {
                return true;
            }
        }
            
        return false;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        cout << i << " " << j << "\n";
        if (visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        for (auto [x, y] : calcNextPos(i, j, grid[i][j])) {
            if (isPosValid(x, y, grid.size(), grid[0].size()) && !visited[x][y] && isConnected(x, y, i, j, grid)) {
                dfs(x, y, grid, visited);
            }
        }
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        dfs(0, 0, grid, visited);

        return visited[grid.size() - 1][grid[0].size() - 1];
    }
};