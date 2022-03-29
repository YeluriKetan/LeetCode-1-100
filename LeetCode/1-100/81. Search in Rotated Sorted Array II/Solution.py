class Solution:
    def binSearch(self, nums: List[int], low: int, high: int, target: int) -> int:
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] < target:
                low = mid + 1
            elif nums[mid] == target:
                return True
            else:
                high = mid - 1
        return False

    def search(self, nums: List[int], target: int) -> int:
        if target == nums[0]: return True
        n = len(nums)
        low, high, dup = 0, n - 1, nums[0]
        while low < high and dup == nums[low] == nums[high]:
            low, high = low + 1, high - 1
        if low > high: return False
        if nums[low] > nums[high]:
            right = nums[high]
            while low + 1 < high:
                mid = (low + high) // 2
                if nums[mid] <= right:
                    high = mid - 1
                else:
                    low = mid
            low += 1 if nums[low + 1] > right else 0
            if target > right:
                return self.binSearch(nums, 0, low, target)
            else:
                return self.binSearch(nums, low + 1, n - 1, target)
        else:
            return self.binSearch(nums, low, high, target)