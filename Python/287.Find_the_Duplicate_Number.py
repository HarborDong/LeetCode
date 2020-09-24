class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """
        left, right = 1, len(nums) - 1
        while left < right:
            middle = (left + right)//2
            left_sum = len([x for x in nums if x <= middle and x >= left])

            if left_sum <= middle - left + 1:
                left = middle + 1
            else:
                right = middle
            
        return left
        """
        slow = fast = 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
        slow = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[fast]
        return slow
        
