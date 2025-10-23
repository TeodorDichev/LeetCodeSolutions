    class Solution {
    public:
        int mySqrt(int x) {
            if (x == 0 || x == 1)
                return x;

            int low = 1;
            int high = x;

            while(low <= high) {
                int mid = low + (high - low) / 2;
                int diff = x / mid;
                if(diff == mid)
                    return mid;
                else if(mid > diff)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            return high;
        }
    };