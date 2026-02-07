class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> cnt;
        for (char& ch : s) {
            if (cnt.count(ch)) {
                return ch;
            }
            cnt.insert(ch);
        }
        return NULL;
    }
};