class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    bool reorderedPowerOf2(int n) {
        // Extract digits
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(digits.begin(), digits.end());

        do {
            if (digits[0] == 0) continue;

            int num = 0;
            for (int d : digits) num = num * 10 + d;

            if (isPowerOfTwo(num)) return true;
        } while (next_permutation(digits.begin(), digits.end()));

        return false;
    }
};
