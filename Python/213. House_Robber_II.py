class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        dynamic programming
        state transform function:
        rob(n) = max(rob(n-1), rob(n-2) + money(n))
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) <= 3:
            return max(nums)
    
        rob0 = nums[0]; rob1 = max(nums[0:2])
        i = 2        
        while i < len(nums) - 1:
            rob_max0 = max(rob0+nums[i], rob1)
            rob0 = rob1; rob1 = rob_max0
            i += 1
        
        nums = nums[-1::-1]    
        rob0 = nums[0]; rob1 = max(nums[0:2])
        i = 2        
        while i < len(nums) - 1:
            rob_max1 = max(rob0+nums[i], rob1)
            rob0 = rob1; rob1 = rob_max1
            i += 1

        return rob_max0 if rob_max0 > rob_max1 else rob_max1
