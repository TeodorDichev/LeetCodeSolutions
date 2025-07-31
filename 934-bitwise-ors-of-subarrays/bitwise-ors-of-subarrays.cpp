class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> dist;

        for (int i = 0; i < n; ++i) {
            auto x = arr[i];
            dist[x]++;
            for (int j = i - 1; j >= 0; --j) {
                auto newOr = arr[j] | x;

                if (arr[j] == newOr)
                    break;
                else
                    arr[j] = newOr;

                dist[newOr]++;
            }
        }

        return dist.size();
    }
};