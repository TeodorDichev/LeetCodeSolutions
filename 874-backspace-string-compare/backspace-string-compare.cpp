class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sStack, tStack;

        for (char ch : s) {
            if (ch == '#') {
                if (!sStack.empty()) sStack.pop();
            } else {
                sStack.push(ch);
            }
        }

        for (char ch : t) {
            if (ch == '#') {
                if (!tStack.empty()) tStack.pop();
            } else {
                tStack.push(ch);
            }
        }

        while (!sStack.empty() && !tStack.empty()) {
            if (sStack.top() != tStack.top()) return false;
            sStack.pop();
            tStack.pop();
        }

        return sStack.empty() && tStack.empty();
    }
};
