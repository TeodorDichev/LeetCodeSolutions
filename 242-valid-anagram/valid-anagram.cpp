class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;

        for (char ch : s) {
            sMap[ch]++;
        }

        for (char ch : t) {
            sMap[ch]--;
        }

        for (auto p : sMap) {
            if (p.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};