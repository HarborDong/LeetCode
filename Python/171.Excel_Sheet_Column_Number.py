class Solution:
    def titleToNumber(self, s: 'str') -> 'int':
        count = 0
        A_num = ord('A') - 1
        for i in range(len(s)):
            count = (ord(s[i]) - A_num) + count * 26
        return count
