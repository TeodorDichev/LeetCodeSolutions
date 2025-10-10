class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), boats = 0;
        for(int i = 0, j = n - 1; i <= j;) {
            int sum = people[i] + people[j];
            if(sum > limit) j--;
            else {
                i++; j--;
            }

            boats++;
        }

        return boats;
    }
};