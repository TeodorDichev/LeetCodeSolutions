class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto dislike : dislikes) {
            int u = dislike[0] - 1;
            int v = dislike[1] - 1;

            graph[u].push_back(v);
            graph[v].push_back(u); 
        }

        vector<int> colors(n, 0); // 0 - unvisited, 1 - parent, 2 - child
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                queue<int> q;
                
                q.push(i);
                colors[i] = 1;

                while(q.size()) {
                    int curr = q.front();
                    q.pop();

                    for (auto edge : graph[curr]) {
                        if (colors[edge] == 0) {
                            int color;
                            if (colors[curr] == 1) color = 2;
                            else if (colors[curr] == 2) color = 1;

                            colors[edge] = color;
                            q.push(edge);
                        } else if (colors[edge] == colors[curr]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};