class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (colors[0] != colors[i]) {
                max_dist = max (max_dist, i);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                max_dist = max(max_dist, n - i - 1);
                break;
            }
        }

        return max_dist;
    }
};