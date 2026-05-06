class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = boxGrid[j][i];
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

        for (int j = 0; j < m; j++) {
            int lowest = n - 1;

            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[lowest][j] = '#';
                    lowest--;
                }
                if (result[i][j] == '*') {
                    lowest = i - 1;
                }
            }
        }
        
        return result;
    }
};