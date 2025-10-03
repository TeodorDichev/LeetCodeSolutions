class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int rows = heightMap.size(), cols = heightMap[0].size();
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    minHeap.push({heightMap[r][c], r, c});
                    heightMap[r][c] = -1;
                }
            }
        }

        int res = 0, max_h = -1;
        while(minHeap.size() > 0) {
            int h = minHeap.top()[0], r = minHeap.top()[1], c = minHeap.top()[2];
            minHeap.pop();
            max_h = max(max_h, h);
            res += max_h - h;

            vector<vector<int>> neighbours = {{r+1,c},{r-1,c},{r,c+1},{r,c-1}};
            for(int i = 0; i < 4; i++) {
                int nr = neighbours[i][0];
                int nc = neighbours[i][1];

                if(nr < 0 || nc < 0 || nr == rows || nc == cols || heightMap[nr][nc] == -1) {
                    continue;
                }

                minHeap.push({heightMap[nr][nc], nr, nc});
                heightMap[nr][nc]= -1;
            }
        }

        return res;
    }
};