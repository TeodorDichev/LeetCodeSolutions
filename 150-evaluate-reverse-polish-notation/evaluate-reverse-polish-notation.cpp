class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                if (token == "+") nums.push(a + b);
                else if (token == "-") nums.push(a - b);
                else if (token == "*") nums.push(a * b);
                else nums.push(a / b);
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};
