class Solution {
public:
    long long getSign(int num, vector<int> primes) {
        long long sign = 1;
        while (num > 0) {
            sign *= primes[num % 10];
            num /= 10;
        }
        return sign;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        long long targetSign = getSign(n, primes);
        for (int i = 0; i < 31; i++) {
            if (getSign(1 << i, primes) == targetSign) {
                return true;
            }
        }

        return false;
    }
};
