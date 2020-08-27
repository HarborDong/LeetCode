class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if len(nums) == 0: return
        end = start = nums[0]
        nums.append(nums[-1])
        
        for num in nums[1:]:
            if num == end + 1:
                end += 1
            else:
                res.append(str(start)) if start == end else res.append(str(start) + "->" + str(end))                    
                start = end = num
        
        return res
            
