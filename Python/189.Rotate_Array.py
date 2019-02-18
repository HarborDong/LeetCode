class Solution:
    def rotate(self, nums: 'List[int]', k: 'int') -> 'None':
        """
        Do not return anything, modify nums in-place instead.
        """
        list_len = len(nums)
        k %= list_len
        if not k: return
        index = 0; j = 0
        for i in range(list_len - 1):
            index += k
            if j == index % list_len:
                j += 1; index = j
                continue
            temp = nums[j]
            nums[j] = nums[index % list_len]
            nums[index % list_len] = temp
        
        return
