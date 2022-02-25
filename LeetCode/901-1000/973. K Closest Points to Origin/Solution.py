import heapq as hq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        closest_points = []
        for point in points:
            dist = point[0] ** 2 + point[1] ** 2
            hq.heappush(closest_points, (-dist, point))
            if len(closest_points) > k:
                hq.heappop(closest_points)
        for i in range(len(closest_points)):
            closest_points[i] = closest_points[i][1]
        return closest_points