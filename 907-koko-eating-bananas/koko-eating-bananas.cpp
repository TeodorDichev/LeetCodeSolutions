class Solution {
    bool canEatAll(vector<int>& piles, int h, int k) {
        for(int i = 0; i < piles.size(); i++) {
            h -= piles[i] / k;
            if(piles[i] % k) h--;
            if(h < 0) return false;
        }

        return h >= 0;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            int k = l + (r - l) / 2;

            if(canEatAll(piles, h, k))
                r = k;
            else 
                l = k + 1;
        }

        return l;
    }
};