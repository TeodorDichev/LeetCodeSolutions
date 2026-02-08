class Solution {
    bool canPlaceBalls(int x, vector<int>& position, int m) {
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        for (int i = 1; i < position.size() && ballsPlaced < m; ++i) {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x) {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }

        return ballsPlaced == m;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = ceil(position[position.size() - 1] / (m - 1.0)), ans = 0;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (canPlaceBalls(mid, position, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};