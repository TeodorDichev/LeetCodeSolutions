class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> dna;
        vector<string> result;
        int n = s.size() - 9;
        for (int i = 0; i < n; ++i) {
            string str = s.substr(i, 10);
            dna[str]++;
        }

        for (auto& pair : dna) {
            if (pair.second > 1) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};