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
    ListNode* deleteDuplicates(ListNode* head) {
        auto *newHead = new ListNode();
        ListNode *prev = newHead;
        ListNode *curr = head;
        int currVal, count;
        while (curr != nullptr) {
            currVal = curr->val;
            prev->next = curr;
            count = 0;
            while (curr != nullptr && curr->val == currVal) {
                curr = curr->next;
                count++;
            }
            if (count > 1) {
                prev->next = nullptr;
            } else {
                prev = prev->next;
            }
        }
        return newHead->next;
    }
};