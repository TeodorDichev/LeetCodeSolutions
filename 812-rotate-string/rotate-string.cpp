class Solution {
public:
    bool rotateString(string s, string goal) {
        int lenS = s.size();
        int lenG = goal.size();

        if (lenS != lenG) {
            return false;
        }

        string ss = s + s;

        for (int i = 0; i < lenG; i++) {
            if (ss.substr(i, lenG) == goal) {
                return true;
            }
        }

        return false;
    }
};