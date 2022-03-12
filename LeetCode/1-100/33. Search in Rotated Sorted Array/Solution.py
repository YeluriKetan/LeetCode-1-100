class Solution:
    def binSearch(self, nums: List[int], low: int, high: int, target: int) -> int:
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            elif nums[mid] == target:
                return mid
            else:
                high = mid - 1
        return -1

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if nums[0] > nums[n - 1]:
            low, high, right = 0, n - 1, nums[n - 1]
            while low + 1 < high:
                mid = (low + high) // 2
                if nums[mid] < right:
                    high = mid - 1
                else:
                    low = mid
            low += 1 if nums[low + 1] > right else 0
            if target > right:
                return self.binSearch(nums, 0, low, target)
            else:
                return self.binSearch(nums, low + 1, n - 1, target)
        else:
            return self.binSearch(nums, 0, n - 1, target)