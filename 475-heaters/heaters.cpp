class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;

        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            
            int distToRight = INT_MAX;
            if (it != heaters.end()) {
                distToRight = *it - house;
            }

            int distToLeft = INT_MAX;
            if (it != heaters.begin()) {
                distToLeft = house - *prev(it);
            }

            int closestHeater = min(distToLeft, distToRight);
            minRadius = max(minRadius, closestHeater);
        }

        return minRadius;
    }
};