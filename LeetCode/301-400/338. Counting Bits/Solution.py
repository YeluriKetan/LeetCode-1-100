class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0: return [0]
        ans, pointer, curr, limit = [0], 0, 1, 1
        while curr <= n:
            if pointer == limit:
                pointer = 0
                limit *= 2
            ans.append(1 + ans[pointer])
            pointer += 1
            curr += 1
        return ans