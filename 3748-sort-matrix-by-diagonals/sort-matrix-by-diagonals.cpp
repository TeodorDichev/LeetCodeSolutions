class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        auto insertionSortDiagonal = [&](int row, int col, bool descending) {
            int i = row, j = col;
            while (i < n && j < n) {
                int r = i, c = j;
                while (r > row && c > col) {
                    int prevR = r - 1, prevC = c - 1;
                    if ((descending && grid[prevR][prevC] < grid[r][c]) ||
                        (!descending && grid[prevR][prevC] > grid[r][c])) {
                        swap(grid[prevR][prevC], grid[r][c]);
                    } else break;
                    r--, c--;
                }
                i++, j++;
            }
        };

        for (int r = 0; r < n; r++)
            insertionSortDiagonal(r, 0, true);

        for (int c = 1; c < n; c++)
            insertionSortDiagonal(0, c, false);

        return grid;
    }
};