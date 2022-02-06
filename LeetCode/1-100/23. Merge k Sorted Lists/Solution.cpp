class Solution {
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* curr = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 == nullptr) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        return head;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        vector<ListNode*> tempList;
        int currSize;
        while (lists.size() > 1) {
            currSize = lists.size();
            for (int i = 0; i < currSize; i += 2) {
                if (i == currSize - 1) {
                    tempList.push_back(lists[i]);
                } else {
                    tempList.push_back(mergeTwoLists(lists[i], lists[i + 1]));
                }
            }
            lists = tempList;
            tempList.clear();
        }
        return lists[0];
    }
};