class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        i = 0
        while n:
            n = n & (n - 1)
            i += 1
        return i
