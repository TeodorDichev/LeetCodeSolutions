class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        double longestDiag = 0.0;

        for(vector<int> rect : dimensions) {
            double currDiag = sqrt(rect[0]*rect[0] + rect[1]*rect[1]);
            int currArea = rect[0]*rect[1];
            if((abs(currDiag - longestDiag) < 1e-9 && maxArea < currArea) || currDiag > longestDiag) {
                maxArea = currArea;
                longestDiag = currDiag;
            }
        }

        return maxArea;
    }
};