class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        transfer function dp[i] = max(dp[i], dp[j] + 1) if nums[i] > nums[j]
        """
        if not nums: return 0
        dp = [1] * len(nums)
        
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return max(dp)
