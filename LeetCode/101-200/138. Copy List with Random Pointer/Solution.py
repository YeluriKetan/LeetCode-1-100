"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None: return None
        old_curr, new_curr = head.next, Node(head.val)
        oldToNew = {head: new_curr}
        while old_curr is not None:
            new_curr.next = Node(old_curr.val)
            new_curr = new_curr.next
            oldToNew[old_curr], old_curr = new_curr, old_curr.next
        old_curr, new_curr = head, oldToNew[head]
        while old_curr is not None:
            new_curr.random = (oldToNew[old_curr.random]) if old_curr.random is not None else None
            old_curr, new_curr = old_curr.next, new_curr.next
        return oldToNew[head]