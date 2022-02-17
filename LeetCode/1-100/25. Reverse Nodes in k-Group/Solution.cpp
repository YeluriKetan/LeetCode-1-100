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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            len++;
        }
        ListNode* newHead = new ListNode();
        ListNode* newCurr = newHead;
        curr = head;
        ListNode* tempHead;
        ListNode* tempTail;
        ListNode* tempCurr;
        for (; len >= k; len -= k) {
            tempTail = curr;
            tempHead = curr;
            curr = curr->next;
            for (int i = 0; i < k - 1; ++i) {
                tempCurr = curr;
                curr = curr->next;
                tempCurr->next = tempHead;
                tempHead = tempCurr;
            }
            newCurr->next = tempHead;
            newCurr = tempTail;
        }
        newCurr->next = curr;
        return newHead->next;
    }
};