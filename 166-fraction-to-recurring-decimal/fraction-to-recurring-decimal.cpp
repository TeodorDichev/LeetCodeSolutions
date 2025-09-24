class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string fraction;

        if (numerator < 0 ^ denominator < 0) fraction.append("-");
            
        long long dividend = abs((long long)numerator);
        long long divisor = abs((long long)denominator);

        fraction.append(to_string(dividend / divisor));    
        long long remainder = dividend % divisor;

        if (remainder == 0)  return fraction;

        fraction.append(".");
        unordered_map<long long, int> map;

        while(remainder != 0) {
            if(map.contains(remainder)) {
                fraction.insert(map[remainder], "(");
                fraction.append(")");
                break;
            }
            map[remainder] = fraction.size();
            remainder *= 10;
            fraction.append(to_string(remainder / divisor));
            remainder %= divisor;
        } 

        return fraction;
    }
};