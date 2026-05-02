class Solution {
    unordered_set<int> getDigits(int n) {
        unordered_set<int> res;
        while (n > 0) {
            res.insert(n % 10);
            n /= 10;
        }

        return res;
    }

public:
    int rotatedDigits(int n) {
        unordered_set<int> validDigits = {0,1,2,5,6,8,9};
        unordered_set<int> goodDigits = {2,5,6,9};
        int res = 0;

        for (int i = 1; i <= n; i++) {
            bool atLeastOneGoodDigit = false;
            for (int digit : getDigits(i)) {
                if (!validDigits.contains(digit)) {
                    atLeastOneGoodDigit = false;
                    break;
                }
                if (!atLeastOneGoodDigit && goodDigits.contains(digit)) {
                    atLeastOneGoodDigit = true;
                }
            }
            if (atLeastOneGoodDigit) {
                res++;
            }
        }

        return res;
    }
};