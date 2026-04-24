class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> occur;

        for (char& ch : moves) {
            occur[ch]++;
        }

        return max(occur['L'], occur['R']) + occur['_'] - min(occur['L'], occur['R']);

    }
};