class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target) {
            return 0;
        }

        int n = words.size();
        int dist = 0;
        for (int i = (startIndex - 1 + n) % n, j = (startIndex + 1) % n; true; i=(i - 1 + n) % n, j=(j + 1)%n) {
            dist++;
            if (words[i] == target) {
                return dist;
            } else if (words[j] == target) {
                return dist;
            }

            if (i == j) {
                if (words[i] == target) {
                    return dist;
                } else {
                    break;
                }
            }
        }

        return -1;
    }
};