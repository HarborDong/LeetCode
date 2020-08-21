class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        """
        bucket sort
        """
        bucket = {}
        if t < 0: return False
        offset = 1 if t > 0 else 0
        
        for i in range(len(nums)):
            index = nums[i] // (t+1)
            
            for j in range(index-offset, index+offset+1):
                if j in bucket and abs(nums[i] - bucket[j]) <= t:
                    return True

            bucket[index] = nums[i]
            
            if (i >= k):
                bucket.pop(nums[i-k] // (t+1))
        
        return False
