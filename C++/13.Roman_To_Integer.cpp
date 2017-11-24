class Solution {
    
public:
    static int romanCharToNum(char s)
    {
        switch (s)
        {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        int res = 0;
        char next = 0;
        int i = 0;
        
        while(i < s.length()) {
            res += romanCharToNum(s.at(i));
            if(s.at(i)== 'I' || s.at(i) == 'X' || s.at(i) == 'C') {
                if((i+1) < s.length()) {
                    next = s.at(i + 1);
                } else {
                    break;
                }
                if(romanCharToNum(s.at(i + 1)) > romanCharToNum(s.at(i))) {
                    res += (romanCharToNum(s.at(i + 1)) - 2*romanCharToNum(s.at(i)));
                    i++;
                }
            }
            i++;
        }
        return res;
    }
};
