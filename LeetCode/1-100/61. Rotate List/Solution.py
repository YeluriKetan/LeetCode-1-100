# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        len, curr, last = 0, head, None
        while curr is not None:
            len, last, curr = len + 1, curr, curr.next
        if len < 2: return head
        k, curr = len - (k % len), head
        if k == len: return head
        while k > 1:
            k, curr = k - 1, curr.next
        newHead, curr.next, last.next = curr.next, None, head
        return newHead
        