class Solution {
    int calcTimeDiff(int start, int end) {
        return min(abs(end - start), (24*60 - abs(end - start)));
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (string str : timePoints) {
            string hours = str.substr(0, 2);
            string mins = str.substr(3, 2);
            minutes.push_back(stoi(hours) * 60 + stoi(mins));
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; i++) {
            int diff = calcTimeDiff(minutes[i+1], minutes[i]);
            if (diff < minDiff) {
                minDiff = diff;
            }
        }

        int diff = calcTimeDiff(minutes[minutes.size() - 1], minutes[0]);
        if (diff < minDiff) {
            minDiff = diff;
        }

        return minDiff;
    }
};