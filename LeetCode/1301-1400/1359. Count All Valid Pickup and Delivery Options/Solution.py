class Solution:
    def countOrders(self, n: int) -> int:
        ans, prime  = 1, 1000000007
        for i in range(1, n + 1):
            ans = (ans * i) % prime
        for i in range(1, 2 * n, 2):
            ans = (ans * i) % prime
        return ans
