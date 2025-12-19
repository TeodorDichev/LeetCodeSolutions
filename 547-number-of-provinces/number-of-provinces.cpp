class Solution {
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // idea 1: build a graph and proceed normaly
        // idea 2: use the given matrix
        // you can check only the upper right part + main diag
        int n = isConnected.size();
        int numOfComponents = 0;
        vector<bool> visited(n);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numOfComponents++;
                dfs(i, isConnected, visited);
            }
        }

        return numOfComponents;
    }
};