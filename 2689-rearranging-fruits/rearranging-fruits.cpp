class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX, n = basket1.size();
        unordered_map<int, int> frequency_map;

        for (int i = 0; i < n; ++i) {
            frequency_map[basket1[i]]++;
            frequency_map[basket2[i]]--;
            m = min(m, min(basket1[i], basket2[i]));
        }

        vector<int> merge;
        for (auto [k, c] : frequency_map) {
            if (c % 2 != 0) return -1;
               
            for (int i = 0; i < abs(c) / 2; ++i) 
                merge.push_back(k);
        }

        if(merge.size() == 0) return 0;

        nth_element(merge.begin(), merge.begin() + merge.size() / 2, merge.end());
        
        long long cost = 0;
            for (int i = 0; i < merge.size() / 2; ++i)
                cost += std::min(2 * m, merge[i]);
        
        return cost;
    }
};
