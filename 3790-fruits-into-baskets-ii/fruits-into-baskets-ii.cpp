class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), res = 0;
        vector<bool> takenBaskets(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(fruits[i] <= baskets[j] && !takenBaskets[j]) {
                    takenBaskets[j] = true;
                    break;
                }
                if(j == n - 1) {
                    res++;
                }
            }
        }
        return res;
    }
};