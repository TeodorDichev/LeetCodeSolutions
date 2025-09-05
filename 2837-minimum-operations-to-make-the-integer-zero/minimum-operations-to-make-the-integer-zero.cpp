class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 0; i <= 60; i++) {
            long long num = num1 - 1LL * i * num2;

            if(num < 0) break;
            if(num >= i && popcount((unsigned long long)num) <= i) return i;
        }

        return -1;
    }
};