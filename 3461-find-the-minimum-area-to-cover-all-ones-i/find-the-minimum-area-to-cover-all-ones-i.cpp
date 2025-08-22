class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        int minRow = m, minCol = n, maxRow = -1, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    if (i < minRow) minRow = i;
                    if (j < minCol) minCol = j;
                    if (i > maxRow) maxRow = i;
                    if (j > maxCol) maxCol = j;
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
