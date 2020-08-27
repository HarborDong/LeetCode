class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        '''
        There are at most two such numbers, space O(1)
        moore voting O(n)
        '''
        record = [0, 0]
        candidates = [0, 0]
        re = []
        
        for num in nums:
            if num == candidates[0]:
                record[0] += 1
            elif num == candidates[1]:
                record[1] += 1
            elif record[0] == 0:
                candidates[0] = num
                record[0] += 1
            elif record[1] == 0:
                candidates[1] = num
                record[1] += 1
            else:
                record = [i - 1 for i in record]
            #print(record, candidates)
        
        if candidates[0] == candidates[1]: candidates.pop()
        
        for candidate in candidates:
            total = sum([1 for num in nums if num == candidate])
            if total > len(nums) // 3:
                re.append(candidate)

        return re

                
