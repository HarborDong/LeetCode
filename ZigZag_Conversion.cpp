class Solution {
public:
    string convert(string s, int numRows) {
        typedef unsigned int uint;
        uint time = 0, length = s.length, j = 0, index = 0;
        string result = "";
        
        if(length < 3) return s;
        
        time = length/(2 * numRows - 1) + (length%(2 *numRows - 1) ? 1:0);
        
        for(uint i = 0; i < numRows; i++, index = 0)
            while(j < time && index < length) {
                if( i == 0 ) {
                    index = (2 * numRows - 2) * i
                    result += s[index];
                }
                
            }
        
    }
};
