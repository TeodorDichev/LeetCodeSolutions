class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (char ch : s) freq[ch - 'a']++;

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({freq[i], 'a' + i});
        }

        string res = "";

        while (pq.size() > 1) {
            auto [cnt1, ch1] = pq.top(); pq.pop();
            auto [cnt2, ch2] = pq.top(); pq.pop();

            res += ch1;
            res += ch2;

            if (cnt1 - 1 > 0) pq.push({cnt1 - 1, ch1});
            if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ch2});
        }

        if (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            if (cnt > 1) return "";
            res += ch;
        }

        return res;
    }
};
