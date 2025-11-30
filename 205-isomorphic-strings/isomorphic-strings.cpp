class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        if (s.size() != t.size()) {
            return false;
        }

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ((sTot.contains(s[i]) && sTot[s[i]] != t[i]) || 
                (tTos.contains(t[i]) && tTos[t[i]] != s[i])) {
                    return false;
            } else {
                sTot[s[i]] = t[i];
                tTos[t[i]] = s[i];
            }
        }
        return true;
    }
};