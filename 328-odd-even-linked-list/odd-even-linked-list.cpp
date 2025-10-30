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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* iter = head;
        ListNode* odd = head;
        ListNode* even = nullptr;
        ListNode* evenHead = nullptr;

        size_t index = 1;
        while(iter) {
            auto curr = iter;
            iter = iter->next;
            if(index & 1) {
                odd->next = curr;
                odd = odd->next;
            } else {
                if(!evenHead) {
                    even = curr;
                    evenHead = curr;
                } else {
                    even->next = curr;
                    even = even->next;
                }
            }
            index++;
        }
        odd->next = evenHead;
        even->next = nullptr;
        return head;
    }
};