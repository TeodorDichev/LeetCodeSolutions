class Solution {
    bool topSortDfsWithCycleDetection(vector<vector<int>>& graph, vector<bool>& visited, 
                                        vector<int>& res, vector<bool>& path, int curr) {
        
        visited[curr] = true;
        path[curr] = true;

        for (auto& node : graph[curr]) {
            if (!visited[node]) {
                if (topSortDfsWithCycleDetection(graph, visited, res, path, node)) {
                    // has cycle
                    return true;
                }
            } else if (path[node]) {
                // has cycle
                return true;
            }
        }

        // no cycle
        path[curr] = false;
        res.push_back(curr);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto& preq : prerequisites) {
            graph[preq[1]].push_back(preq[0]);
        }
        vector<bool> visited(numCourses);
        vector<bool> path(numCourses, false);
        vector<int> res;
        for (int i = 0; i < numCourses; i++)  {
            if (!visited[i]) {
                if (topSortDfsWithCycleDetection(graph,visited,res,path,i)) {
                    return {};
                }
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};