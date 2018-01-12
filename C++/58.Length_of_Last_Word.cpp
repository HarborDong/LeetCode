class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator start = s.rbegin(), end = s.rend();
        string::reverse_iterator i = s.rbegin();
        string::reverse_iterator begin = s.rend();
        bool firstChar = false;
        while(i != s.rend()) {
            if(*i == ' '){
                if(firstChar) break;
            } else {
                if(!firstChar) firstChar = true, begin = i;
            }
            i++;
        }
        
        return i - begin;
    }
};
