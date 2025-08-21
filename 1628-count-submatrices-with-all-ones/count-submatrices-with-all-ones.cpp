class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        if(m == 0) return 0;
        int n = mat[0].size(), ans = 0;

        vector<int> height(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[j] = mat[i][j] ? height[j] + 1 : 0;
            }

            vector<int> sum(n);
            stack<int> st;

            for (int j = 0; j < n; j++) {
                while (!st.empty() && height[st.top()] >= height[j]) {
                    st.pop();
                }
                
                if (!st.empty()) {
                    int p = st.top();
                    sum[j] = sum[p] + height[j] * (j - p);
                } 
                else {
                    sum[j] = height[j] * (j + 1);
                }
                
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};