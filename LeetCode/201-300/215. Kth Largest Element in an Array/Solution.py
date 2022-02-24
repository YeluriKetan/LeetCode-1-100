import heapq as hq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for i in range(k):
            hq.heappush(nums[i])
        for i in range(k, len(nums)):
            hq.heappush(nums[i])
            hq.heappop()
        return heap[0]