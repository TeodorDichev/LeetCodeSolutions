class Solution {
    int getIslandSize(vector<vector<int>>& grid, pair<int,int> start) {
        vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push(start);
        grid[start.first][start.second] = 0;
        
        int res = 0;
        while(q.size()) {
            auto [x,y] = q.front(); q.pop();
            res++;
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                if (grid[nx][ny]) { 
                    grid[nx][ny] = 0;
                    q.push({nx, ny}); 
                }
            }
        }

        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    int size = getIslandSize(grid, {i,j});
                    res = max(res, size);
                }
            }
        }
        
        return res;
    }
};