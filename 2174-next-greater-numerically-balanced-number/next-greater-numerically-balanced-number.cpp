class Solution {
public:
    bool check(int x) {
        vector<int> cnt(10);
        while(x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }

        for(int d = 0; d < 10; d++)
            if(cnt[d] > 0 && cnt[d] != d)
                return false;
        
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224444; i++)
            if(check(i))
                return i;

        return -1;
    }
};