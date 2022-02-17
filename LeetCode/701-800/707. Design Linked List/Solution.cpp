class MyLinkedList {
    class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int v) {
            val = v;
            next = nullptr;
        }
    };

    ListNode* head;
    ListNode* tail;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        } else {
            ListNode* curr = head;
            while (index-- > 0) {
                curr = curr->next;
            }
            return curr->val;
        }
    }

    void addAtHead(int val) {
        auto newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    void addAtTail(int val) {
        auto newNode = new ListNode(val);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        } else if (index < size) {
            index--;
            ListNode* curr = head;
            while (index-- > 0) {
                curr = curr->next;
            }
            auto newNode = new ListNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
            size++;
        } else if (index == size) {
            addAtTail(val);
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            if (size == 0) {
                return;
            }
            head = head->next;
            if (size == 1) {
                tail = nullptr;
            }
            size--;
        } else if (index < size) {
            if (index == size - 1) {
                index--;
                ListNode *curr = head;
                while (index-- > 0) {
                    curr = curr->next;
                }
                curr->next = curr->next->next;
                tail = curr;
            } else {
                index--;
                ListNode *curr = head;
                while (index-- > 0) {
                    curr = curr->next;
                }
                curr->next = curr->next->next;
            }
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */