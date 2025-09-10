class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // stores the most commonly spoken language amongst users without a common language
        unordered_map<int, int> mostCommonLanguage;
        unordered_map<int, bool> people;

        for(int m = 0; m < friendships.size(); ++m) {
            int friend1Index = friendships[m][0] - 1;
            int friend2Index = friendships[m][1] - 1;
            bool flag = true;
            // we keep in friendships only people without common languages
            for(int i = 0; i < languages[friend1Index].size() && flag; i++) {
                for(int j = 0; j < languages[friend2Index].size(); j++) {
                    if(languages[friend1Index][i] == languages[friend2Index][j]) {
                        flag = false;
                        // they have a common language
                        friendships.erase(friendships.begin() + m);
                        // so we dont skip anything
                        m--;
                        break;
                    }
                } 
            }

            // They dont have a common language
            // add their languages to the hast set
            if(flag && !people[friend1Index]) {
                for (int i = 0; i < languages[friend1Index].size(); i++) {
                    mostCommonLanguage[languages[friend1Index][i]]++;
                }
                people[friend1Index] = true;
            }
            if(flag && !people[friend2Index]) {
                for (int i = 0; i < languages[friend2Index].size(); i++) {
                    mostCommonLanguage[languages[friend2Index][i]]++;
                }
                people[friend2Index] = true;
            }
        }

        // after this in friendships there are only pairs which do not share a common language
        return people.size() - findEntryWithLargestValue(mostCommonLanguage);
    }

    int findEntryWithLargestValue(unordered_map<int, int> map) 
    { 
        pair<int, int> entryWithMaxValue = make_pair(0, 0); 

        unordered_map<int, int>::iterator currentEntry; 
        for (currentEntry = map.begin(); currentEntry != map.end(); ++currentEntry) { 
            if (currentEntry->second > entryWithMaxValue.second) { 
                entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second); 
            }    
        } 

        return entryWithMaxValue.second; 
    } 
};