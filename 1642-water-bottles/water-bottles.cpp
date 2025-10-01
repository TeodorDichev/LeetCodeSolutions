class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, rem = numBottles % numExchange;

        numBottles = numBottles / numExchange; 
        while(numBottles > 0) {
            int currRem = (numBottles + rem) % numExchange;
            res += numBottles;
            numBottles = (numBottles + rem) / numExchange;
            rem = currRem;
        }

        return res;
    }
};