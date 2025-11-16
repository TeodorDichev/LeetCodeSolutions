class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0, fresh = 0;
        queue<pair<int,int>> rotten;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    rotten.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;
        if(rotten.empty()) return -1;

        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!rotten.empty()) {
            int currSize = rotten.size();
            while(currSize--) {
                auto [x, y] = rotten.front();
                rotten.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        fresh--;
                        rotten.push({i, j});
                    }
                }
            }
            res++;
        }

        if(fresh != 0) return -1;
        return res - 1;
    }
};