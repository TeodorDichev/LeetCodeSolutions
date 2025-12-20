class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // directed graph
        vector<vector<int>> graph(n, vector<int>());
        unordered_map<int, int> mapIn;
        unordered_map<int, int> mapOut;
        for (auto& vec : trust) {
            int from = vec[0];
            int to = vec[1];

           mapOut[from]++;
           mapIn[to]++;
        }

        for (int i = 1; i <= n; i++) {
            if (mapIn[i] == n - 1 && mapOut[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};