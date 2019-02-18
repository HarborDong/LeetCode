class Solution:
    def findRepeatedDnaSequences(self, s: 'str') -> 'List[str]':
        ret = set(); str_dict = set()
        start_index_range = range(len(s) - 9)
        for i in start_index_range:
            if s[i:i+10] in str_dict:
                ret.add(s[i:i+10])
            else:
                str_dict.add(s[i:i+10])
        return list(ret)
        
