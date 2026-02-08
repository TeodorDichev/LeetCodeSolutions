class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end());

        int end = points[0][1];
        int arrows = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};