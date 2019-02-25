class Solution:
    def rob(self, nums: 'List[int]') -> 'int':
        """
        rob [A, B, C, D, E]
        status transferation function
        if we rob house E, max(A->E) =  E + max(A->C)
        else max(A->E) = max(A->D)
        """
        rob = []
        if (len(nums) == 0): return 0
        if (len(nums) == 1): return nums[0]
        if (len(nums) == 2): return max(nums)
        rob.append(nums[0]); rob.append(max(nums))
        
        for i in range(2, len(nums)):
            rob_i_max = max(nums[i] + rob[i - 2], rob[i - 1])
            rob.append(rob_i_max)
        
        return max(rob)
        """
        better one, space O(1)
        """
        rob = [0, 0]
        for i in range(len(nums)):
            rob_i = max(nums[i] + rob[0], rob[1])
            rob[0] = rob[1]; rob[1] = rob_i
            
        return max(rob)
