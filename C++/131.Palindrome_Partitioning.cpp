class Solution {
public:
 typedef unsigned int uint;

    unsigned int* longestPalindrome(string &s) {
        unsigned int i = 0;
        string temp = "$";
        unsigned int* record;
        unsigned int c_index = 2, i_mirror = 2, right_margin = 2;
        unsigned int max_length = 0, res_index = 0;
        unsigned int start_index = 0;
        
        while(s[i] != '\0') {
            temp += "#";
            temp += s[i];
            i++;
        }
        temp += "#&";
        record = new unsigned int[temp.length()];
        memset(record, 1, sizeof(unsigned int)*temp.length());

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
        return record;
    }
    bool isPalindrome(int left, int right, uint* recode) {
        int index = right + left + 2;
        if(recode[index] >= (right - left + 1))
            return true;
        else
            return false;
        
    }
    void partitionHelper(string s, int left, uint* record, 
                         vector<vector<string>> &ret, vector<string> &element) {
        if (left == s.length()) {
            ret.push_back(element);
            return;
        }
        for(int i = left; i < s.length(); i++) {
            if (!isPalindrome(left, i, record)) {
                continue;
            }
            element.push_back(s.substr(left, i - left + 1));
            partitionHelper(s, i + 1, record, ret, element);
            element.pop_back();
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        uint *record = longestPalindrome(s);
        vector<vector<string>> ret;
        vector<string> element;
        partitionHelper(s, 0, record, ret, element);
        return ret;
    }
};
