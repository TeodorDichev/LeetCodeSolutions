class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};