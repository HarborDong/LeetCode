class Solution {
public:
    void reverseWords(string &s) {
        string::iterator left = s.begin(), right = s.begin(), index = s.begin();
        int word = 0, number = 0;       
        reverse(s.begin(), s.end());
        
        while(right < s.end()){
            if(*right != ' ') {
                if(!word) {
                    word = 1;
                    if(number) {
                    *index = ' '; index++;
                    }
                    left = index;
                }    
                *index = *right; index++;
            } else {
                if(word) {
                    reverse(left, index);
                    number++;
                    word = 0; 
                }
            }
            right++;
        }
        if(word) reverse(left, index);
        s.erase(index, s.end());
        return;
    }
};
