class Solution {
public:
    /**
     * 1.用unordered_set做个hash字典,用来判断字符串时候存在在wordDict里面
     * 2.DP思路,如果起点pos之前的字符串可以分割,判断pos开始的字符串是否可分割
     *          如果起点pos之前的字符串不可分割,判断pos+1之前的字符串是否可分割
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<bool> matchFlag(s.length() + 1, false);
        int maxStrLen = 0;
        int end = 0;
        for(int i = 0; i < wordDict.size(); i++) {
            if(wordDict[i].length() > maxStrLen) {
                maxStrLen = wordDict[i].length();
            }
            dict.insert(wordDict[i]);
        }
        if(maxStrLen > s.length()) maxStrLen = s.length();

        matchFlag[0] = true;
        for (int pos = 0; pos < s.length() && pos <= end; pos++) {
            int posEnd = s.length() < (pos + maxStrLen) ? s.length() : (pos + maxStrLen);
            for (int i = pos; matchFlag[pos] && i < posEnd; i++) {
                if(dict.count(s.substr(pos, i - pos + 1))) {
                    if(end < i + 1) end = i + 1;
                    matchFlag[i + 1] = true;
                }
            }
        }
        return matchFlag[s.length()];
    }
};
