class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        numsLen = len(nums)
        numsKDict = {}
        if k > numsLen: k = numsLen
        
        for i in range(k):
            if nums[i] in numsKDict:
                numsKDict[nums[i]] += 1
                return True
            else:
                numsKDict[nums[i]] = 1;
        
        for i in range(k, numsLen):
            if nums[i] in numsKDict:
                numsKDict[nums[i]] += 1
                if numsKDict[nums[i]] > 1:
                    return True
            else:
                numsKDict[nums[i]] = 1;
            numsKDict[nums[i - k]] -= 1
            
        return False
