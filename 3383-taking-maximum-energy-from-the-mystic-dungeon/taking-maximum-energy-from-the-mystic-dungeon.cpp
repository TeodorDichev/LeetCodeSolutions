class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> arr(n);
        for(int i = n - 1; i >= 0; i--) {
            if(n - i <= k) arr[i] = energy[i];
            else arr[i] = arr[i + k] + energy[i];
        }

        return *std::max_element(arr.begin(), arr.end());
    }
};