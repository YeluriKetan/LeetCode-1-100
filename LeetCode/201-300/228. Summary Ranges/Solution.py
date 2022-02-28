class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return []
        begin = end = nums[0]
        ans = []
        for i in range(1, len(nums)):
            if nums[i] == end + 1:
                end = nums[i]
            else:
                if begin == end:
                    ans.append(str(begin))
                else:
                    ans.append(f"{begin}->{end}")
                begin = end = nums[i]
        if begin == end:
            ans.append(str(begin))
        else:
            ans.append(f"{begin}->{end}")
        return ans