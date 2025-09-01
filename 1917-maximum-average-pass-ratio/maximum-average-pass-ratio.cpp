class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        priority_queue<pair<double, pair<int,int>>> heap;

        for(auto &c : classes) {
            heap.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        
        while (extraStudents--) {
            auto [delta, pair] = heap.top(); 
            heap.pop();
            int pass = pair.first + 1;
            int total = pair.second + 1;
            heap.push({gain(pass, total), {pass, total}});
        }
        
        double sum = 0.0;
        while (!heap.empty()) {
            auto [delta, pair] = heap.top(); 
            heap.pop();
            sum += (double)pair.first / pair.second;
        }
        
        return sum / classes.size();
    }
};