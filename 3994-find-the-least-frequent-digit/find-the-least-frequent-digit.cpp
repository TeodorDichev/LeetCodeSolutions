class Solution {
public:
    int getLeastFrequentDigit(int n) {
        if (n == 0) return 0;
        
        vector<int> counts(10, 0);
        while (n > 0) {
            counts[n % 10]++;
            n /= 10;
        }

        int minDigit = -1;
        int minFreq = INT_MAX;

        for (int i = 0; i <= 9; ++i) {
            if (counts[i] > 0 && counts[i] < minFreq) {
                minFreq = counts[i];
                minDigit = i;
            }
        }
        return minDigit;
    }
};