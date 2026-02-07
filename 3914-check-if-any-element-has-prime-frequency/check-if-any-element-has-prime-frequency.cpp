class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0) return false;

        int limit = static_cast<int>(sqrt(num));
        for (int i = 3; i <= limit; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int& num : nums) {
            map[num]++;
        }

        for (auto [num, cnt] : map) {
            if (isPrime(cnt)) {
                return true;
            }
        }

        return false;
    }
};