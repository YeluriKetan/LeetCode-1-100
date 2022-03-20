from typing import List

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        def min_rotation(check):
            count, total = 0, 0
            for i in range(len(tops)):
                if tops[i] == check and bottoms[i] == check:
                    continue
                elif tops[i] == check:
                    pass
                elif bottoms[i] == check:
                    count += 1
                else:
                    return -1
                total += 1
            return min(count, total - count)
        ans = min_rotation(tops[0])
        if ans > -1: return ans
        return min_rotation(bottoms[0]) if tops[0] != bottoms[0] else -1
