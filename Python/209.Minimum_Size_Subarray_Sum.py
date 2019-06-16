class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        res = len(nums) + 1
        start = 0; end = len(nums)
        cur = start
        sums = 0
        while cur < end:
            sums += nums[cur]
            while sums - nums[start] >= s:
                sums -= nums[start]
                start += 1

            if sums >= s and res > cur - start + 1:
                res = cur - start + 1
            
            cur += 1               
        
        if res == len(nums) + 1: return 0
        return res
