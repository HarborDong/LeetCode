class Solution {
public:
    void needleMode(string needle, int *next) {
        int length = needle.length();
        int i = 0, j = 0;
        next[0] = -1;
        memset(next, 0, length);
        while(j < length-1) {
            if(i == -1 || needle[i] == needle[j]){
                i++;
                j++;
                next[j] = i;
            } else {
                i = next[i];
            }
        }
        return;        
    }
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int next[needle.length()];
        if(!haystack.length() || !needle.length() || needle.length() < haystack.length()) return -1;
        needleMode(needle, next);
        int k = 0;
        while(k < needle.length()) {
            cout << next[k];
        }
        cout << endl;
        while(i < haystack.length() && j < needle.length()) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++, j++;
            } else {
                j = next[j];
            }            
        }
        if(j == needle.length()) {
            return i - j;
        } else {
            return -1;
        }
    }
};
