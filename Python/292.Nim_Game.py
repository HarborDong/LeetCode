class Solution:
    def canWinNim(self, n: int) -> bool:
        """
        left four stones to friends
        """
        if n % 4 == 0:
            return False
        else:
            return True
        
