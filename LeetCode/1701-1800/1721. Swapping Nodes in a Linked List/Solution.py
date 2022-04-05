# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        curr, counter = head, k
        while counter > 1: curr, counter = curr.next, counter - 1
        other, counter = curr.next, 1
        while other: other, counter = other.next, counter + 1
        other = head
        while counter > 1: other, counter = other.next, counter - 1
        temp = curr.val
        curr.val = other.val
        other.val = temp
        return head