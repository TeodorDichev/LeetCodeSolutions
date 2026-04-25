class Solution {
    bool check(long long limit, int side, int k, vector<long long>& arr) {
        for (long long start : arr) {
            long long end = start + side * 4LL - limit;
            long long cur = start;

            for (int i = 0; i < k - 1; i++) {
                auto it = lower_bound(arr.begin(), arr.end(), cur + limit);
                // auto it = ranges::lower_bound(arr, cur + limit);

                if (it == arr.end() || *it > end) {
                    cur = -1;
                    break;
                }
                cur = *it;
            }

            if (cur >= 0) {
                return true;
            }
        }

        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.push_back(y);
            } else if (y == side) {
                arr.push_back(side + x);
            } else if (x == side) {
                arr.push_back(side * 3LL - y);
            } else if (y == 0) {
                arr.push_back(side * 4LL - x);
            }
        }

        sort(arr.begin(), arr.end());

        // binary search on answer
        long long left = 1;
        long long right = side;
        int ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (check(mid, side, k, arr)) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};