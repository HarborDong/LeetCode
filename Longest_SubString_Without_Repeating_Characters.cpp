class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0, max = 0;
        int start = -1;
        int charIndex[256];
        memset(charIndex, -1, sizeof(int)*256);
        while(s[index] != '\0')
        {

            if(start < charIndex[s[index]])
            {
                start = charIndex[s[index]];
            }
            if(index - start > max)
                max = index - start;

            charIndex[s[index]] = index;
            index++;

        }
        return max;
    }
};
