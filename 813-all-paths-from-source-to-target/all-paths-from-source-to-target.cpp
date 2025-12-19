class Solution {
    vector<vector<int>> results;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // all possible paths => dfs
        // we need to keep count of visited
        // input gives as the list as a adjeicent list
        vector<int> path;
        dfs(graph, path, 0, graph.size() - 1);

        return results;
    }

    void dfs(const vector<vector<int>>& graph, vector<int>& path, int currNode, int targetNode) {
        path.push_back(currNode);

        if (currNode == targetNode) {
            results.push_back(path);
            path.pop_back();
            return;
        }

        for (int node : graph[currNode]) {
            dfs(graph, path, node, targetNode);
        }

        path.pop_back();
    }
};