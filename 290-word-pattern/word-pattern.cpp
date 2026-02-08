class Solution {
    vector<string> split(string s) {
        vector<string> res;
        string currStr = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                res.push_back(currStr);
                currStr = "";
            } else {
                currStr += s[i];
            }
        }

        res.push_back(currStr);
        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> patternMap;
        unordered_map<string, char> wordsMap;
        vector<string> words = split(s);

        if (words.size() != pattern.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            if (patternMap.count(pattern[i])) {
                if (patternMap[pattern[i]] != words[i]) {
                    return false;
                }
            } else {
                if (wordsMap.count(words[i])) {
                    return false;
                }
                wordsMap[words[i]] = pattern[i];
                patternMap[pattern[i]] = words[i];
            }
        }

        return true;
    }
};