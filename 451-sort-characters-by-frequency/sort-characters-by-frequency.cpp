class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;

        for (auto ch : s) {
           mp[ch]++;
        }

        for (auto [ch, fr] : mp) {
            pq.push({fr, ch});
        }

        string res;
        while(pq.size()) {
            auto [freq, ch] = pq.top(); pq.pop();
            while(freq--) {
                res += ch;
            }
        }

        return res;
    }
};