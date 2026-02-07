class Solution {
    bool contains(const deque<char>& substr, unordered_map<char, int> chars) {
        for (char ch : substr) {
            if (chars[ch] == 0) {
                return false;
            }
            chars[ch]--;
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.size();
        if (s2.size() < s1Size) {
            return false;
        }

        unordered_map<char, int> chars;
        for (char ch : s1) {
            chars[ch]++;
        }

        deque<char> substr;
        for (int i = 0; i < s1Size; i++) {
            substr.push_back(s2[i]);
        }

        for (int i = s1Size; i < s2.size(); i++) {
            if (contains(substr, chars)) {
                return true;
            }

            substr.pop_front();
            substr.push_back(s2[i]);
        }

        return contains(substr, chars);
    }
};