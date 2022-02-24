class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        new_x = 0
        x_copy = x
        while x_copy > 0:
            new_x *= 10
            new_x += x_copy % 10
            x_copy //= 10
        return new_x == x