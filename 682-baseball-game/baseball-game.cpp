class Solution {
public:
    int calPoints(vector<string>& operations) {
        int res = 0;
        stack<int> nums;

        for(auto ch : operations) {
            if (ch == "C" && !nums.empty()) {
                nums.pop();
            }
            else if (ch == "D" && !nums.empty()) {
                nums.push(nums.top() * 2);
            }
            else if (ch == "+") {
                int curr = nums.top();
                nums.pop();
                int prev= nums.top();
                nums.push(curr);
                nums.push(curr + prev);
            }
            else {
                nums.push(stoi(ch));
            }
        }

        while(!nums.empty()) {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};