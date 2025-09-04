class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xToz = abs(z - x);
        int yToz = abs(z - y);

        if(xToz == yToz) return 0;
        return (xToz < yToz ? 1:2); 
    }
};