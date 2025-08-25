class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int row = 0, col = 0;
        vector<int> result;
        
        for(int diagonal = 0; diagonal < n + m - 1; diagonal++) {
            if(diagonal % 2 == 0) {
                row = min(diagonal, n - 1);
                col = diagonal - row;

                while(row >= 0 && col < m) {
                    result.push_back(mat[row--][col++]);
                }
            }
            else {
                col = min(diagonal, m - 1);
                row = diagonal - col;

                while(row < n && col >= 0){
                    result.push_back(mat[row++][col--]);
                }
            }
        }

        return result;
    }
};