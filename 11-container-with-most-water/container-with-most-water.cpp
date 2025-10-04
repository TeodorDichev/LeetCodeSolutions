class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, i = 0, j = height.size() - 1;;
        while(i < height.size() && j >= 0 && i != j) {
            if(height[i] > height[j]) {
                int area = height[j] * abs(i - j);
                max_area = max(max_area, area);
                j--;
            }
            else {
                int area = height[i] * abs(i - j);
                max_area = max(max_area, area);
                i++;
            }
        }

        return max_area;
    }
};