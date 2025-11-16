/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;

        while(head) {
            vals.push_back(head->val);
            head = head->next;
        }

        vector<int> result(vals.size(), 0);
        stack<int> s;
        for(int i = 0; i < vals.size(); i++) {
            while(!s.empty() && vals[i] > vals[s.top()]) {
                result[s.top()] = vals[i];
                s.pop();
            }
            s.push(i);
        }

        return result;
    }
};