class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magaMap;

        for (char ch : magazine) {
            magaMap[ch]++;
        }

        for (char ch : ransomNote) {
            if (magaMap[ch]) {
                magaMap[ch]--;
            } else {
                return false;
            }
        }

        return true;
    }
};