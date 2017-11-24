class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, j = 0;
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        
        while(i < strs[0].length()) {
            j = 1;    
            while(j < strs.size()) {
                if(strs[0][i] == strs[j][i]) {
                    j++;
                } else {
                    return strs[0].substr(0,i);
                }
            }
            i++;
        }
        return strs[0];        
    }
};
