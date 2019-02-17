from functools import cmp_to_key
def cmp_str(x, y):
    str1 = str(x) + str(y)
    str2 = str(y) + str(x)
    if str1 > str2:
        return 1
    elif str1 == str2:
        return 0
    else:
        return -1
    
class Solution:
    def largestNumber(self, nums: 'List[int]') -> 'str':        
        var = sorted(nums, key=cmp_to_key(cmp_str), reverse=True)
        ret = ''
        for i in var:
            if ret != '0':
                ret += str(i)
        return ret 
    """
    python3 sorted function don't support self-defined compare function
    we can use cmp_to_key or __lt__
    """

