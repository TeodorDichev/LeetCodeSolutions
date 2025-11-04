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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *prev = nullptr;

        int carryOver = 0;
        while(l1 || l2 || carryOver) {
            int val1 = 0;
            if(l1) {
                val1 = l1->val;
                l1 = l1->next;
            }

            int val2 = 0;
            if(l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carryOver;
            int digit = sum % 10;
            carryOver = sum / 10;
            if(head) {
                prev->next = new ListNode(digit, nullptr);
                prev = prev->next;
            } else {
                head = new ListNode(digit, nullptr);
                prev = head;
            }

            sum /= 10;
        }

        return head;
    }
};