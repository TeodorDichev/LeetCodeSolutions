class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto& op : operations) {
            if(op.compare("X++") == 0 || op.compare("++X") == 0)
                res++;
            else
                res--;
        }

        return res;
    }
};