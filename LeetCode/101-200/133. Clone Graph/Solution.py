"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""


class Solution:
    def dfs(self, node: 'Node', map: 'Dict'):
        new_node = Node(node.val)
        map[new_node.val] = new_node
        for child in node.neighbors:
            if child.val not in map:
                self.dfs(child, map)
            new_node.neighbors.append(map[child.val])

    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        new_map = dict()
        self.dfs(node, new_map)
        return new_map[node.val]
        