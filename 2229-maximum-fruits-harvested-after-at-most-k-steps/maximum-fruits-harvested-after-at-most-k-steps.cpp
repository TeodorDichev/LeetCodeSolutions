class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxSum = 0, left = 0, sum = 0;

        for(int right = 0; right < fruits.size(); right++) {
            sum += fruits[right][1];
            while(left <= right && getMinSteps(fruits[left][0], fruits[right][0], startPos) > k)
                sum -= fruits[left++][1];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int getMinSteps(int left, int right, int start) {
        int leftToGo = std::abs(start-left) + right - left;
        int rightToGo = std::abs(start-right) + right - left;
        return min(leftToGo, rightToGo);
    }
};