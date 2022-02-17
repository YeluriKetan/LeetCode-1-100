/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr = headA;
        while (curr != nullptr) {
            curr->val *= -1;
            curr = curr->next;
        }
        curr = headB;
        ListNode *ans = nullptr;
        while (curr != nullptr) {
            if (curr->val < 0) {
                ans = curr;
                break;
            } else {
                curr = curr->next;
            }
        }
        curr = headA;
        while (curr != nullptr) {
            curr->val *= -1;
            curr = curr->next;
        }
        return ans;
    }
};