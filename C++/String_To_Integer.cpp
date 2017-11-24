/*****************
 * 
 *
 */
class Solution {
public:
    int myAtoi(string str) {
#define MAX_INT ((int)0x7FFFFFFF)
#define MIN_INT ((int)0x80000000)
        int length = str.length();
        int result = 0, first_nonzero = 0;
        int flag = 1;
        int i = 0;
        int digit_number = 0;
        if(length == 0) return result;
        
        /* skip space*/
        while(isspace(str[i]))
            i++;
        
        /* + - */
        if(str[i] == '-') {
            flag = -1;
            i++;
        } else if(str[i] == '+') {
            flag = 1;
            i++;
        } 
           
        while(str[i] == '0') {
            if(!first_nonzero) {
                i++;
            } else {
                first_nonzero = 1;
            }
        }
        
        while(isdigit(str[i])) {
            if(result > MAX_INT/10)
                return flag == 1 ? MAX_INT : MIN_INT; 
            result = result * 10 + (str[i] - '0');
            i++; 
        }
        
        if(result < 0)
            if(flag == 1)
                return MAX_INT;
            else
                return MIN_INT;
        
        return flag == 1? result:-result;
    }
};
