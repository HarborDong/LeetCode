class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        a = m & n; i = 0
        if a == 0: return a
        while m + 2 ** i<= n:
            a =  a & (m + 2 ** i)
            i += 1
        return a
        """
        better one
        """
        while m < n: n &= (n - 1)
        return n
        
