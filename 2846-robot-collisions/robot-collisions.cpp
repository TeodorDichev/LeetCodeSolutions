class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> indexes;
        stack<int> st;

        for (int i = 0; i < positions.size(); i++) {
            indexes.push_back(i);
        }

        sort(indexes.begin(), indexes.end(), [&](int l, int r) {
            return positions[l] < positions[r]; });

        for (int curr : indexes) {
            if (directions[curr] == 'R') {
                st.push(curr);
            } else {
                while (st.size() && healths[curr] > 0) {
                    int top = st.top(); st.pop();
                    if (healths[top] > healths[curr]) {
                        healths[top]--;
                        healths[curr] = 0;
                        st.push(top); // no point if checking top 0
                    } else if (healths[top] < healths[curr]) {
                        healths[curr]--;
                        healths[top] = 0;
                    } else {
                        healths[curr] = 0;
                        healths[top] = 0;
                    }
                }
            }
        }

        vector<int> res;
        for (int health : healths) {
            if (health > 0) {
                res.push_back(health);
            }
        }

        return res;
    }
};