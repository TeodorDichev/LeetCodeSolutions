class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles;
        int emptyBottles = 0;
        int bottlesDrunk = 0;

        while(fullBottles != 0 || emptyBottles >= numExchange) {
            if(fullBottles > 0) {
                // drink
                bottlesDrunk += fullBottles;
                emptyBottles += fullBottles;
                fullBottles = 0;
                continue;
            }
            
            // exchange
            while(emptyBottles - numExchange >= 0) {
                emptyBottles -= numExchange;
                numExchange++;
                fullBottles++;
            }
            
        }

        return bottlesDrunk;
    }
};