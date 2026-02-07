class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int res = 0;
        unordered_map<char, int> sMap;

        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]] = i;
        }

        for (int i = 0; i < t.size(); i++) {
            res += abs(sMap[t[i]] - i);
        }
        
        return res;
    }
};