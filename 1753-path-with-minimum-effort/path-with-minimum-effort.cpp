class Solution {
    struct Node {
        int row, col;       // cell coordinates
        int weight;     // maximum effort to reach this cell so far

        bool operator<(const Node& other) const {
            return weight > other.weight; // min-heap
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //dijkstra
        // for (dx, dy) in [(1,0),(-1,0),(0,1),(0,-1)]:
        //     ni = i + dx
        //     nj = j + dy
        // if (ni, nj) in bounds:
        //     process neighbor
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
        distances[0][0] = 0;
        
        priority_queue<Node> nextToProcess;
        nextToProcess.push({0,0,0});

        while (nextToProcess.size()) {
            auto curr = nextToProcess.top();
            nextToProcess.pop();

            if (curr.weight > distances[curr.row][curr.col]) continue;

            vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [row, col] : directions) {
                int nRow = curr.row + row;
                int nCol = curr.col + col;
                if (nRow >= rows || nRow < 0 || nCol >= cols || nCol < 0) continue;

                int newWeight = max(curr.weight, abs(heights[nRow][nCol] - heights[curr.row][curr.col]));
                if (newWeight < distances[nRow][nCol]) {
                    distances[nRow][nCol] = newWeight;
                    nextToProcess.push({nRow, nCol, newWeight});
                }
            }
        }

        return distances[rows-1][cols-1];
    }
};