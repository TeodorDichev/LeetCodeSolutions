class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // I am back baby. THE GRIND >>>
        int n = s1.size();

        char s1_even[26];
        char s2_even[26];

        char s1_odd[26];
        char s2_odd[26];

        for (int i = 0; i < n; i++) {
            if (i % 2) {
                s1_odd[s1[i] - 'a']++;
                s2_odd[s2[i] - 'a']++;
            } else {
                s1_even[s1[i] - 'a']++;
                s2_even[s2[i] - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (s1_odd[i] != s2_odd[i] || s1_even[i] != s2_even[i]) {
                return false;
            }
        }

        return true;
    }
};