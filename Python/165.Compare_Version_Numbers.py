class Solution:
    def compareVersion(self, version1: 'str', version2: 'str') -> 'int':
        ver_list1 = version1.split('.')
        ver_list2 = version2.split('.')
        
        for i in range(min(len(ver_list1), len(ver_list2))):
            if int(ver_list1[i]) > int(ver_list2[i]):
                return 1
            elif int(ver_list1[i]) < int(ver_list2[i]):
                return -1
        
        if len(ver_list1) < len(ver_list2):
            for i in range(len(ver_list1), len(ver_list2)):
                if int(ver_list2[i]):
                   return -1
        elif len(ver_list2) < len(ver_list1):
            for i in range(len(ver_list2), len(ver_list1)):
                if int(ver_list1[i]):
                   return 1
        
        return 0
    """
    2-4 lines Python, 3 different ways
    Solution 1: Pad with izip_longest with fillvalue=0

    def compareVersion(self, version1, version2):
        splits = (map(int, v.split('.')) for v in (version1, version2))
        return cmp(*zip(*itertools.izip_longest(*splits, fillvalue=0)))
    Solution 2: Pad with [0] * lengthDifference

    def compareVersion(self, version1, version2):
        v1, v2 = (map(int, v.split('.')) for v in (version1, version2))
        d = len(v2) - len(v1)
        return cmp(v1 + [0]*d, v2 + [0]*-d)
    
    Solution 3: Recursive, add zeros on the fly

    def compareVersion(self, version1, version2):
        main1, _, rest1 = ('0' + version1).partition('.')
        main2, _, rest2 = ('0' + version2).partition('.')
        return cmp(int(main1), int(main2)) or \
               len(rest1+rest2) and self.compareVersion(rest1, rest2)
    """
