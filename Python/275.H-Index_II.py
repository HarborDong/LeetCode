class Solution:
    def hIndex(self, citations: List[int]) -> int:
        left, right = 0, len(citations) - 1
        total = len(citations)
        citations.reverse()
        res = 0
        while left <= right:
            middle = (left + right)//2
            #print(left, middle, right)
            if middle + 1<= citations[middle]:
                res = middle + 1
                left = middle + 1
            else:
                right = middle -1
        
        return res
