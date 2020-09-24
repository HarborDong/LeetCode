# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        
        while left <= right:
            middle = (left + right)//2
            if isBadVersion(middle):
                right = middle - 1
            else:
                left = middle + 1
        
        return left
        
