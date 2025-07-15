class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int index1 = 0, index2 = 0;
        while(index1 < word1.size() || index2 < word2.size()) {
            if(index1 < word1.size()) {
                result += word1[index1++];
            }
            if (index2 < word2.size()) {
                result += word2[index2++];
            }
        }
        return result;
    }
};