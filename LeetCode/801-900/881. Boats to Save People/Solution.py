class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        left, right, ans = 0, len(people) - 1, 0
        while left <= right:
            if people[right] + people[left] <= limit: left += 1
            right, ans = right - 1, ans + 1
        return ans