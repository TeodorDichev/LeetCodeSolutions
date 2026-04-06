#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        vector<pair<int,int>> obsPairs;
        for (auto& ob : obstacles) {
            obsPairs.push_back({ob[0], ob[1]});
        }
        sort(obsPairs.begin(), obsPairs.end());

        // Directions: North, East, South, West
        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        pair<int,int> pos = {0, 0};
        int dir = 0;

        int maxDistSq = 0;

        for (int command : commands) {
            if (command == -1) {
                dir = (dir + 1) % 4; // turn right
                continue;
            }
            if (command == -2) {
                dir = (dir + 3) % 4; // turn left
                continue;
            }

            for (int step = 0; step < command; step++) {
                pair<int,int> nextPos = {pos.first + directions[dir].first,
                                         pos.second + directions[dir].second};

                if (binary_search(obsPairs.begin(), obsPairs.end(), nextPos)) {
                    break;
                }

                pos = nextPos;
                maxDistSq = max(maxDistSq, pos.first * pos.first + pos.second * pos.second);
            }
        }

        return maxDistSq;
    }
};