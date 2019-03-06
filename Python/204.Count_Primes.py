class Solution:
    """
    import math
    def isPrime(self, n: int) -> bool:
        bound = math.ceil(math.sqrt(n))
        for i in self.database:
            if n % i == 0:
                return False
            if i >= bound:
                break
        self.database.append(n)
        return True
    
    def countPrimes(self, n: int) -> int:
        self.database = []
        count = 0
        if n <= 2: return count
        if n >= 3: count += 1; self.database.append(2)
        for i in range(3, n, 2):
            if self.isPrime(i):
                count += 1

        return count
    """
    import math
    def countPrimes(self, n: int) -> int:
        if n < 3: return 0
        prime = [1] * n
        prime[0] = 0; prime[1] = 0
        for i in range(2, math.ceil(math.sqrt(n))):
            if prime[i]:
                prime[i*i:n:i] = [0] * len(prime[i*i:n:i])
        
        return sum(prime)
