class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count;
        for (char c : t) count[c]++;

        int left = 0, minLen = INT_MAX, start = 0;
        int required = t.size();

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (count[c] > 0) required--;   // found a needed char
            count[c]--;                     // decrement regardless

            // shrink window from left
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                count[d]++;
                if (count[d] > 0) required++; // need this char again
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};