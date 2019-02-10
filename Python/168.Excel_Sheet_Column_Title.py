class Solution:
    def convertToTitle(self, n: 'int') -> 'str':
        result = ''
        A_asc = ord('A')
        while n > 0:
            n -= 1
            r = n % 26
            n = n // 26
            result = chr(r + A_asc) + result
        
        return result
