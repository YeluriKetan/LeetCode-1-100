class Solution:
    def maxArea(self, height: List[int]) -> int:
        low, high, max_water, prev = 0, len(height) - 1, 0, -1
        while low < high:
            max_water = max(max_water, min(height[low], height[high]) * (high - low))
            if height[low] < height[high]:
                prev = height[low]
                while low < high and height[low] <= prev: low += 1
            else:
                prev = height[high]
                while low < high and height[high] <= prev: high -= 1
        return max_water