class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                if index != i:
                    nums[index] = nums[i]
                index += 1
                
        for i in range(index, len(nums)):
            nums[i] = 0
            
