class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;
        while(end > begin) {             
            if(!isalnum(*end)) {
                end--; continue;
            }
            if(!isalnum(*begin)) {
                begin++; continue;
            }
            if(tolower(*begin) == tolower(*end)) {
                begin++; end--;
            } else {
                return false;
            }
        }
        return true;        
    }
};
