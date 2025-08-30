class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Could work for any n.n board with 3x3 sub-boxes
        int n = board.size();

        vector<vector<bool>> row(n, vector<bool>(n, false));
        vector<vector<bool>> col(n, vector<bool>(n, false));
        vector<vector<bool>> box(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                int b = (i/3)*3 + j/3;

                if (row[i][num] || col[j][num] || box[b][num])
                    return false;

                row[i][num] = col[j][num] = box[b][num] = true;
            }
        }

        return true;
    }
};
