/***
 * the abs of '-1' is illegel when type is int.
 */
class Solution {
public:
#define SIGN_FLAG 0x80000000
#define MAX_INT 0x7fffffff
    int divide(int dividend, int divisor) {
        int ret = 0, remainder = 0 , i = 0 ;
        int diff_flag = ((dividend ^ divisor) & SIGN_FLAG) ? -1 : 1;
        if(dividend == 0) return 0;
        if(divisor == 0) return MAX_INT;
        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if (dividend != SIGN_FLAG)
                return -dividend;
            else 
                return MAX_INT;
        }
        if(divisor == SIGN_FLAG) {
            if(dividend == SIGN_FLAG)
                return 1;
            else
                return 0;
        }
        if(dividend == SIGN_FLAG) {
            remainder = dividend - diff_flag * divisor;
            ret++;
        } else {
            remainder = dividend;
        }
       
        while (abs(remainder) >= abs(divisor)) {

            if(abs(remainder) >= abs(divisor << i)) {

                remainder -= diff_flag * (divisor << i) ;
                ret += (1 << i);
                i++;
            } else {
                i = 0;
            }
        }
        return diff_flag * ret;;        
    }
};
