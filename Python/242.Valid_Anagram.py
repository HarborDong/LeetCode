class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict_s = {}
        for ch in s:
            if ch in dict_s:
                dict_s[ch] += 1
            else:
                dict_s[ch] = 1
        
        for ch in t:
            if ch in dict_s:
                dict_s[ch] -= 1
            else:
                return False
            
        for ch, num in dict_s.items():
            if num != 0:
                return False
        
        return True
