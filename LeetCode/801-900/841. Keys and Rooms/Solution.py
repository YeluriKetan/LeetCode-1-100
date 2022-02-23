from collections import deque
from typing import List


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        keys = deque()
        n = len(rooms)
        visited = set()
        keys.append(0)
        while len(keys) > 0:
            curr = keys.popleft()
            visited.add(curr)
            for next_key in rooms[curr]:
                if next_key not in visited:
                    keys.append(next_key)
        return len(visited) == n