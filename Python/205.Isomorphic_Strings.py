class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:        
        if len(s) != len(t): return False
        s_dict = {}; t_dict = {} 
        st = zip(s, t)
        print(set(st))
        for s_ch, t_ch in st:
            if s_ch in s_dict and t_ch in t_dict:
                if s_dict[s_ch] != t_ch or \
                   s_ch != t_dict[t_ch]:
                    return False
            else:
                if not s_ch in s_dict and \
                   not t_ch in t_dict:
                    s_dict[s_ch] = t_ch
                    t_dict[t_ch] = s_ch
                else:
                    return False
            
        return True
