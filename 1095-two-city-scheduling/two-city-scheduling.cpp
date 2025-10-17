bool comp(const vector<int>& trip1,const vector<int>& trip2) {
    return trip1[0] - trip1[1] < trip2[0] - trip2[1];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);

        int result = 0;
        int n = costs.size() / 2;
        for(int i = 0; i < n; i++) {
            result += costs[i][0] + costs[i + n][1];
        }

        return result;
    }
};