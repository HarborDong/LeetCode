class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return True if n and n & (n - 1) == 0 else False
