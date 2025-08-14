class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for (int i = 0; i < num.size() - 2; ++i) {
            string sub = num.substr(i, 3);
            if(goodInt(sub, sub[0]) && (res == "" || res[0] < sub[0])) {
                res = sub;
            }
        }
        return res;
    }

    bool goodInt(string sub, char c) {
        for(char s : sub) {
            if(s != c) {
                return false;
            }
        }
        return true;
    }
};