class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0;
        int n = customers.size();
        vector<int> arrToMax(n, 0);
        for (int i = 0; i < n; i++) {
            arrToMax[i] = customers[i] * grumpy[i];
            if (grumpy[i] == 0) {
                res += customers[i];
            }
        }

        int maxSum = 0;
        deque<int> subArr;
        for (int i = 0; i < minutes; i++) {
            subArr.push_back(arrToMax[i]);
            maxSum += arrToMax[i];
        }

        int currSum = maxSum;
        for (int i = minutes; i < n; i++) {
            int currSum = currSum - subArr.front() + arrToMax[i];
            maxSum = max(maxSum, currSum);
            subArr.pop_front();
            subArr.push_back(arrToMax[i]);
        }

        return res + max(maxSum, currSum);
    }
};