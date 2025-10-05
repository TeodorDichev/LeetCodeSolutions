class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, cols - 1);
        }
        for (int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, rows - 1, j);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int r, int c) {
        int rows = h.size(), cols = h[0].size();
        visited[r][c] = true;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            if (visited[nr][nc]) continue;
            if (h[nr][nc] < h[r][c]) continue;
            dfs(h, visited, nr, nc);
        }
    }
};
