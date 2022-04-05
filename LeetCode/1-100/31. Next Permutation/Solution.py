class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        def reverse_part(left: int, right: int =len(nums) - 1):
            while left < right:
                temp = nums[left]
                nums[left] = nums[right]
                nums[right] = temp
                left, right = left + 1, right - 1

        pointer = len(nums) - 2
        while pointer >= 0 and nums[pointer] >= nums[pointer + 1]: pointer -= 1
        if pointer == -1: reverse_part(0)
        else:
            next = len(nums) - 1
            while next > pointer and nums[next] <= nums[pointer]: next -= 1
            temp = nums[pointer]
            nums[pointer] = nums[next]
            nums[next] = temp
            reverse_part(pointer + 1)