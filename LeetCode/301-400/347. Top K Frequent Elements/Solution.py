import heapq as hq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_map = {}
        for n in nums:
            if n in count_map:
                count_map[n] += 1
            else:
                count_map[n] = 1
        count_list = []
        for n, n_count in count_map.items():
            hq.heappush(count_list, (n_count, n))
            if len(count_list) > k:
                hq.heappop(count_list)
        for i in range(len(count_list)):
            count_list[i] = count_list[i][1]
        return count_list