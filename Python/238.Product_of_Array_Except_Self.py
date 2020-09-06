class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        right = left = 1
        length = len(nums)
        
        for i in range(length):
            res[i] *= left
            res[length - i - 1]  *= right
            left *= nums[i]
            right *= nums[length - i - 1]
        
        return res
