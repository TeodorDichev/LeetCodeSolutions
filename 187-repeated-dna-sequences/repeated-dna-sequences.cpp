class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};

        auto enc = [](char c) {
            switch (c) {
                case 'A': return 0;
                case 'C': return 1;
                case 'G': return 2;
                default:  return 3; // 'T'
            }
        };

        unordered_set<int> seen;
        unordered_set<int> dup;

        int code = 0;

        for (int i = 0; i < 9; ++i) {
            code = (code << 2) | enc(s[i]);
        }

        const int mask = (1 << 20) - 1;

        for (int i = 9; i < n; ++i) {
            code = ((code << 2) | enc(s[i])) & mask;

            if (!seen.insert(code).second) {
                dup.insert(code);
            }
        }

        vector<string> res;

        for (int code : dup) {
            string t(10, 'A');
            int x = code;
            for (int i = 9; i >= 0; --i) {
                int v = x & 3;
                if (v == 0) t[i] = 'A';
                else if (v == 1) t[i] = 'C';
                else if (v == 2) t[i] = 'G';
                else t[i] = 'T';
                x >>= 2;
            }
            res.push_back(t);
        }

        return res;
    }
};


// intuative solution
// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<string, int> dna;
//         vector<string> result;
//         int n = s.size() - 9;
//         for (int i = 0; i < n; ++i) {
//             string str = s.substr(i, 10);
//             dna[str]++;
//         }

//         for (auto& pair : dna) {
//             if (pair.second > 1) {
//                 result.push_back(pair.first);
//             }
//         }

//         return result;
//     }
// };