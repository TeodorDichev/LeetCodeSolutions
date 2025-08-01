class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(i > 1 && j > 0 && j < i)
                    result[i].push_back(result[i-1][j-1] + result[i-1][j]);
                else
                    result[i].push_back(1);
            }
        }

        return result;
    }
};