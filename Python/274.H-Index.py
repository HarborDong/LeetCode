class Solution:
    def hIndex(self, citations: List[int]) -> int: 
        #if not citations: return 0
        res, above= 0, 0
        length = len(citations)
        index_array = [0] * (length + 1)
        
        for citation in citations:
            if citation <= length:
                index_array[citation] += 1
            else:
                above += 1

        for i in range(length, -1, -1):
            above += index_array[i]            
            if above >= i:
                res = i
                break

        return res
