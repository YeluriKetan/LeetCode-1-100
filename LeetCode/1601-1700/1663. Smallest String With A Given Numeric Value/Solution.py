class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        z, x = (k - n) // 25, (k - n) % 25
        if x == 0: return 'a' * (n - z) + "z" * z
        return 'a' * (n - z - 1) + chr(ord('a') + x) + "z" * z