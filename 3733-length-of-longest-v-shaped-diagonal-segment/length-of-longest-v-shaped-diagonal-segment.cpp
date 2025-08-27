class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        int total = rows * cols * 4 * 2;
        vector<int> memo(total, -1);

        auto idx = [&](int x, int y, int dir, int turn) {
            return ((x * cols + y) * 4 + dir) * 2 + turn;
        };
        
        function<int(int,int,int,bool,int)> dfs = 
            [&](int cx, int cy, int direction, bool turn, int target) -> int {
                int nx = cx + dirs[direction][0];
                int ny = cy + dirs[direction][1];

                if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != target)
                    return 0; 

                if (memo[idx(nx, ny, direction, turn)] != -1)
                    return memo[idx(nx, ny, direction, turn)];

                int maxStep = dfs(nx, ny, direction, turn, 2 - target);
                if (turn)
                    maxStep = max(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
                
                memo[idx(nx, ny, direction, turn)] = maxStep + 1;
                return maxStep + 1;
            };

        int result = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    for(int dir = 0; dir < 4; dir++) {
                        result = fmax(result, dfs(i, j, dir, true, 2) + 1);
                    }
                }
            }
        }

        return result;
    }
};