class Solution {
    bool checkForOtherPoints(const vector<vector<int>>& points, int i, int j) {
    int x1 = points[i][0], y1 = points[i][1];
    int x2 = points[j][0], y2 = points[j][1];

    for (int k = i + 1; k < j; k++) {
        int x = points[k][0], y = points[k][1];
        if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
            return false;
        }
    }
    
    return true;
}   

public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int res = 0, n = points.size();

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(points[i][0] <= points[j][0] && points[i][1] >= points[j][1] 
                    && checkForOtherPoints(points, i, j))
                    res++;
            }
        }

        return res;
    }
};