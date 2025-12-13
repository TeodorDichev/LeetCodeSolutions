class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (auto node : lists) {
            if (node) pq.push({node->val, node});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();

            curr->next = new ListNode(val);
            curr = curr->next;

            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};
