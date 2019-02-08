class Solution:
    def findPeakElement(self, nums: 'List[int]') -> 'int':
        """
        the algorithm time complexity log(n) hints Binary Search. 
        condition1 nums[i] != nums[i+1], nums[i] < nums[i+1] or
        nums[i] > nums[i+1]. condition2 nums[-1] and nums[n] are -∞
        if nums[i] < nums[i+1], then the peak point locate at range(i+1 , n)
        """
        if len(nums) == 1:
            return 0;
        r_index = len(nums) - 1
        l_index = 0

        while l_index < r_index:
            m_index = (l_index + r_index) // 2

            if nums[m_index] < nums[m_index + 1]:
                l_index = m_index + 1
            else:
                r_index = m_index
        
        return l_index
