class Solution {
    unordered_map<char, pair<int, int>> coordinates = {
        {'A',{0,0}}, {'B',{0,1}}, {'C',{0,2}}, {'D',{0,3}}, {'E',{0,4}}, {'F',{0,5}},
        {'G',{1,0}}, {'H',{1,1}}, {'I',{1,2}}, {'J',{1,3}}, {'K',{1,4}}, {'L',{1,5}},
        {'M',{2,0}}, {'N',{2,1}}, {'O',{2,2}}, {'P',{2,3}}, {'Q',{2,4}}, {'R',{2,5}},
        {'S',{3,0}}, {'T',{3,1}}, {'U',{3,2}}, {'V',{3,3}}, {'W',{3,4}}, {'X',{3,5}},
        {'Y',{4,0}}, {'Z',{4,1}}
    };

    int getDistance(int a, int b) {
        if (a == 26) return 0; // unused finger
        char c1 = 'A' + a;
        char c2 = 'A' + b;

        auto [x1, y1] = coordinates[c1];
        auto [x2, y2] = coordinates[c2];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int rec(int k, int f1, int f2, string& word,
            vector<vector<vector<int>>>& dp) {

        if (k == word.size()) return 0;

        if (dp[k][f1][f2] != -1) return dp[k][f1][f2];

        int target = word[k] - 'A';

        // use finger 1
        int res1 = getDistance(f1, target) +
                   rec(k + 1, target, f2, word, dp);

        // use finger 2
        int res2 = getDistance(f2, target) +
                   rec(k + 1, f1, target, word, dp);

        return dp[k][f1][f2] = min(res1, res2);
    }

public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(
                27, vector<int>(27, -1))
        );

        return rec(0, 26, 26, word, dp);
    }
};