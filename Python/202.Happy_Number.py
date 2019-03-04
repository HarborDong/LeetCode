class Solution:
    def isHappy(self, n: int) -> bool:
        sqrt = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
        existed = set()
        while n not in existed:
            existed.add(n)
            new_n = 0
            while n:
                var = n % 10;
                n //= 10;
                new_n += sqrt[var]
                
            if new_n == 1:
                return True
            else:
                n = new_n
        
        return False
