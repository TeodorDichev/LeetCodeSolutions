class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddInN = ((n % 2 == 1) ? (n / 2 + 1) : (n / 2));
        long long evenInN = n - oddInN;

        long long oddInM = ((m % 2 == 1) ? (m / 2 + 1) : (m / 2));
        long long evenInM = m - oddInM;

        return oddInN * evenInM + evenInN * oddInM;
    }
};