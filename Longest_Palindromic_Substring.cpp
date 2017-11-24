class Solution {
public:
    typedef unsigned int uint;

    string longestPalindrome(string s) {
        unsigned int i = 0;
        string temp = "$";
        unsigned int* record;
        unsigned int c_index = 2, i_mirror = 2, right_margin = 2;
        unsigned int max_length = 0, res_index = 0;
        unsigned int start_index = 0;
        if(s.length() == 0) return "";
        
        while(s[i] != '\0') {
            temp += "#";
            temp += s[i];
            i++;
        }
        temp += "#&";
        record = new unsigned int[temp.length()];
        memset(record, 0 , sizeof(unsigned int)*temp.length());

        i = 2;
        while(temp[right_margin] != '&')
        {
           
            if(record[i_mirror] < record[c_index] + c_index - i) {
                record[i] = record[i_mirror];
                i++;
                i_mirror = 2*c_index - i;
            } else {
                right_margin++;
                if(temp[right_margin] != temp[2*i - right_margin]) {
                    c_index = i;
                    right_margin--;
                    record[i] = right_margin - i;
                    if(record[i] > max_length) {
                        max_length = record[i];
                        res_index = i;
                    }
                    i++;
                                
                    if(i > right_margin)
                    {
                        right_margin = i;
                        c_index = i;
                    }
                    i_mirror = 2*c_index - i;
                }
            }
        }
        c_index = (res_index - 2)/2;
        if(max_length % 2) {
            start_index = c_index - max_length/2;
        } else {
            start_index = c_index + 1 - max_length/2;
        }
        return s.substr(start_index, max_length);
    }
};
