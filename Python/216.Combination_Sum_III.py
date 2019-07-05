class Solution:
    def combinationHelper(self, imin: int, imax: int, k: int, n: int, res: list) -> bool:
        if k > 1:
            if n / k >= (imax - 1):
                return False
            elif n / k <= imin:
                return False
        elif k == 1:
            if n in range(imin, imax):
                self.res.append(res + [n])
                return True
            else:
                return False
        for i in range(imin, imax):
            res.append(i)
            res1 = self.combinationHelper(i + 1, imax, k - 1, n - i, res)
            res.pop()
        return
        
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.res = []
        self.combinationHelper(1, 10, k , n, [])
        return self.res
            
