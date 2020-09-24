class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        length = len(nums) + 1
        xor = 0
        for i in range(length):
            xor ^= i
        
        for num in nums:
            xor ^= num
            
        return xor
