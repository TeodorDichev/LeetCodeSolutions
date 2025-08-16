class Solution {
public:
    int maximum69Number (int num) {
        int del = pow(10, int(floor(log10(num))));
        while(del > 0) {
            if((num / del) % 10 == 6) {
                return num + del * 3;
            }
            del /= 10;
        }
        return num;
    }
};