class Solution {
private:
struct Comparator {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second; // min
            }
            return a.first < b.first; // max
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (auto word : words) {
            map[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;
        for (auto [k, v] : map) {
            pq.push({v, k});
        }

        vector<string> res;
        while (k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};