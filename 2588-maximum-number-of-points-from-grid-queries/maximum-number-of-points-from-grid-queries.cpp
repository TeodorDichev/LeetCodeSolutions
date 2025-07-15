
class Solution {
public:
    std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        int totalCells = rows * cols;
        std::vector<int> result(queries.size());

        // Priority queue (min-heap) storing {value, row, col}
        std::priority_queue<std::tuple<int, int, int>, 
                            std::vector<std::tuple<int, int, int>>, 
                            std::greater<>> minHeap;

        // Boolean visited array
        std::vector<bool> visited(totalCells, false);

        // Start BFS from (0,0)
        minHeap.push({grid[0][0], 0, 0});
        visited[0] = true;
        int points = 0;

        // Sort queries with index to assign results correctly
        std::vector<std::pair<int, int>> indexedQueries;
        for (int i = 0; i < queries.size(); i++)
            indexedQueries.push_back({queries[i], i});
        std::sort(indexedQueries.begin(), indexedQueries.end());

        // 4-direction movement (up, down, left, right)
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Process each query in sorted order
        for (auto &[query, idx] : indexedQueries) {
            while (!minHeap.empty() && std::get<0>(minHeap.top()) < query) {
                auto [val, r, c] = minHeap.top();
                minHeap.pop();
                points++;

                for (auto &[dr, dc] : dir) {
                    int nr = r + dr, nc = c + dc;
                    int pos = nr * cols + nc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[pos]) {
                        visited[pos] = true;
                        minHeap.push({grid[nr][nc], nr, nc});
                    }
                }
            }
            result[idx] = points;
        }

        return result;
    }
};
