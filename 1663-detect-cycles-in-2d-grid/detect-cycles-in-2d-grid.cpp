class Solution {
    // we build undirected graph and detect cycles in it
    // there is an edge between two vertices only if they are the same letter

    bool validPos(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    bool checkForCycle(int i, int j, 
                       vector<vector<char>>& grid, 
                       vector<vector<bool>>& visited, 
                       int rows, int cols) {

        pair<int,int> prev = {-1,-1};
        queue<pair<int,int>> q;
        q.push({i,j});

        while(q.size()) {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();

            if (visited[curr_row][curr_col] && prev.first == curr_row && prev.second == curr_col) {
                return true;
            }

            visited[curr_row][curr_col] = true;

            for (auto& [d_r, d_c] : dirs) {
                int n_r = curr_row + d_r;
                int n_c = curr_col + d_c;
                if (validPos(n_r, n_c, rows, cols) &&
                    grid[curr_row][curr_col] == grid[n_r][n_c] && 
                    !visited[n_r][n_c]) {

                    q.push({n_r, n_c});
                }
            }

            prev = {curr_row, curr_col};

        }
        
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    bool cycle = checkForCycle(i, j, grid, visited, rows, cols);
                    if (cycle) {
                        cout << i << " " << j;
                        return true;
                    }
                }
            }
        }

        return false;
    }
};