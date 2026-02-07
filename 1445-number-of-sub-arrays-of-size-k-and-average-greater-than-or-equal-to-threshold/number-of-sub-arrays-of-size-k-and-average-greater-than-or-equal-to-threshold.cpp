class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        deque<int> subArr;
        int currSum = 0;
        for (int i = 0; i < k; i++) {
            currSum += arr[i];
            subArr.push_back(arr[i]);
        }

        if (currSum / k >= threshold) {
            res++;
        }

        for (int i = k; i < arr.size(); i++) {
            currSum += arr[i];
            currSum -= subArr.front();

            subArr.pop_front();
            subArr.push_back(arr[i]);

            if (currSum / k >= threshold) {
                res++;
            }
        }

        return res;
    }
};