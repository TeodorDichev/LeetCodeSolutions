class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prevSorted = "";
        
        for (auto& w : words) {
            string sorted = w;
            sort(sorted.begin(), sorted.end());
            if (sorted != prevSorted) {
                res.push_back(w);
                prevSorted = sorted;
            }
        }
        return res;
    }
};
