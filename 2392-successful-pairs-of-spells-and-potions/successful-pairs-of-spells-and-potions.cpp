class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> result(n,0);

        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++) {
            
            long long min = (success+spells[i]-1)/spells[i];

            if(min <= potions[m-1]) {
                result[i] = m-(lower_bound(potions.begin(), potions.end(), min) - potions.begin());
            }
        }

        return result;
    }
};