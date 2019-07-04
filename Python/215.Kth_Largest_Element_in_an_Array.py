class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        '''
        k times partition
        '''
        end = len(nums) - 1; start = 0; j = 0
        while start <= end:
            m = start + 1; n = end
            while m <= n:
                if nums[m] > nums[j]:
                    m += 1
                else:
                    nums[n], nums[m] = nums[m], nums[n]
                    n -= 1
            nums[j], nums[n] = nums[n], nums[j]

            if n < k - 1:
                start, n = n+1, end
            elif n > k - 1:
                start, end = 0, n -1
            else:
                return nums[n]
            j = start
