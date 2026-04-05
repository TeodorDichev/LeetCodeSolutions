class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> position = {0, 0};
        for (char move : moves) {
            if (move == 'U') {
                position.first--;
            } else if (move == 'D') {
                position.first++;
            } else if (move == 'L') {
                position.second--;
            } else if (move == 'R') {
                position.second++;
            }
        }

        return position.first == 0 && position.second == 0;
    }
};