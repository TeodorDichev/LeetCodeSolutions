class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dryDays;
        unordered_map<int, int> map;
        vector<int> result(rains.size(), -1);
        
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                result[i] = 1;
            } else {
                int lake = rains[i];

                if(map.find(lake) != map.end()) {
                    int lastRainDay = map[lake];
                    auto up = dryDays.upper_bound(lastRainDay);
                    if(up == dryDays.end()) return {};

                    result[*up] = lake;
                    dryDays.erase(up);
                }

                map[lake] = i;
            }
        }

        return result;
    }
};