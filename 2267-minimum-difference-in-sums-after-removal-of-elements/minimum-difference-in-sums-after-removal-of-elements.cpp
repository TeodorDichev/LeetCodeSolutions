class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        vector<long long> leftMins(n);
        vector<long long> rightMaxs(n);
        long long leftSum = 0, rightSum = 0, minDiff = LLONG_MAX;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < k; i++) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
        }
        leftMins[k-1] = leftSum;

        for (int i = k; i < n - k; i++) {
            int x = nums[i];
            if(x < maxHeap.top()) {
                leftSum += x - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(x);
            }
            leftMins[i] = leftSum;
        }

        for (int i = n - 1; i >= n - k; i--) {
            minHeap.push(nums[i]);
            rightSum += nums[i];
        }
        rightMaxs[n-k] = rightSum;

        for (int i = n - k - 1; i >= k; i--) {
            int x = nums[i];
            if(x > minHeap.top()) {
                rightSum += x - minHeap.top();
                minHeap.pop();
                minHeap.push(x);
            }
            rightMaxs[i] = rightSum;
        }

        for (int i = k -1; i < n-k; i++) {
            minDiff = min (minDiff, leftMins[i] - rightMaxs[i+1]);
        }

        return minDiff;
    }
};