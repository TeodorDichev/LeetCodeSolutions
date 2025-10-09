class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> freeTimes(n);

        for(int i = 0; i < m; i++) {
            long long time = 0;
            for(int j = 0; j < n; j++) {
                time = max(time, freeTimes[j]) + skill[j] * mana[i];
            }
            freeTimes[n-1] = time;
            for(int j = n-2; j>=0;j--) {
                freeTimes[j] = freeTimes[j+1] - skill[j+1]*mana[i];
            }
        }

        return freeTimes[n-1];
    }
};