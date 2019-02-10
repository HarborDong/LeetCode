class Solution:
    def majorityElement(self, nums: 'List[int]') -> 'int':
        nums_dict = {}
        c = (len(nums) + 1) // 2
        for val in nums:
            nums_dict[val] = nums_dict[val] + 1 if val in nums_dict else 1
            if nums_dict[val] >= c:
                return val
    """
    the array is non-empty and the majority element always exist in the array.
    Boyer-Moore Voting Algorithm
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
    """
        
