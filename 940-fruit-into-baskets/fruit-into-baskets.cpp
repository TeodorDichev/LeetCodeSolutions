class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Sliding window approach
        int maxVal = 0, prev = 0, total = 0;
        pair<int, int> baskets = {fruits[0], fruits[0]};
        
        for(int fruit : fruits) {
            if(baskets.second != fruit) {
                if(baskets.first != fruit)
                    total = prev;
                baskets.first = baskets.second;
                baskets.second = fruit;
                prev = 0;
            }
            prev++;
            total++;
            maxVal = max(maxVal, total);
        }
        return maxVal;
        
    }
};