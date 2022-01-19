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
    ListNode *detectCycle(ListNode *head) {
        ListNode* first = head;
        ListNode* second = head;
        while (true) {
            if (first == nullptr) {
                return nullptr;
            }
            first = first->next;
            for (int i = 0; i < 2; ++i) {
                if (second == nullptr) {
                    return nullptr;
                }
                second = second->next;
            }
            if (first == second) {
                break;
            }
        }
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};