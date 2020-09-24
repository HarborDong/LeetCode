class Solution:
    def nthUglyNumber(self, n: int) -> int:
        res = [1]
        i2, i3, i5 = 0, 0, 0 

        while n - 1:
            tmp = min(res[i2]*2, res[i3]*3, res[i5]*5)
            if tmp == res[i2]*2: i2 += 1
            if tmp == res[i3]*3: i3 += 1
            if tmp == res[i5]*5: i5 += 1
            res.append(tmp)
            n -= 1
        
        return res.pop()
