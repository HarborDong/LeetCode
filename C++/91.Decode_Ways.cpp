class Solution {
public:
    /**
     * nums[i] is the number of why when i is the end of string,
     * max_sum[i] = nums[i-1] + nums[i-1] <= 2?nums[i-2] + 0;
     *
     */
    int numDecodings(string s) {
        int preNum1 = 0, preNum2 = 0;
        int curNum = 0;
        int index = 0;
        if(s.length() == 0) return 0;
        for(;index < s.length(); index++) {
            if(index > 0) {
                if(preNum2 == 0) {
                    if(s[index - 1] != '0' && s[index - 1] < '3' && s[index] < '7') {
                        preNum2 = 1;
                    }
                } else {
                    if(s[index - 1] > '2' || (s[index - 1] == '2' && s[index] > '6')
                       || s[index - 1] == '0') {
                        preNum2 = 0;
                    }
                }
            }
            
            if (s[index] > '0' && preNum1 == 0) {
                preNum1 = 1;
            } else if (s[index] == '0') {
                preNum1 = 0;
            }

            curNum = preNum1 + preNum2;
            if(curNum == 0) return 0;
            preNum2 = preNum1;
            preNum1 = curNum;
        }
        return curNum;
    }
};
