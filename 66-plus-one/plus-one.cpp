class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lastDigit = digits[digits.size() - 1];
        if (lastDigit != 9) {
            digits[digits.size() - 1]++;
            return digits;
        }

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }

        // only nines
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};