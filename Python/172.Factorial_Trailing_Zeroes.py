class Solution:
    def trailingZeroes(self, n: 'int') -> 'int':
        count = 0
        while n:
            n = n // 5
            count += n
        
        return count
