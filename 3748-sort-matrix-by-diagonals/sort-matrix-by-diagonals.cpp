class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        int i = 0, j = 0, k = 0;
        while(k < n) {
            i = k;
            j = 0;
            priority_queue<int> max_priority_queue;
            while(i < n && j < n) {
                max_priority_queue.push(grid[i][j]);
                i++; j++;
            }

            i = k;
            j = 0;
            while(i < n && j < n) {
                grid[i][j] = max_priority_queue.top();
                max_priority_queue.pop();
                i++; j++;
            }
            k++;
        }
        
        k = 1;
        while(k < n) {
            i = 0;
            j = k;
            priority_queue<int> min_priority_queue;
            while(i < n && j < n) {
                min_priority_queue.push(grid[i][j]);
                i++; j++;
            }
            
            i--; j--;
            while(i >= 0 && j >= 0) {
                grid[i][j] = min_priority_queue.top();
                min_priority_queue.pop();
                i--; j--;
            }
            k++;
        }

        return grid;
    }
};