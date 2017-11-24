class Solution {
public:
    int reverse(int x) {
#define MAX_INT 0x7FFFFFFF
#define MIN_INT ((int)0X80000000)
#define INT_BIT 10
        int flag = x < 0 ? 1:0;
        int bit_num = 0;
        int temp = 0;

        while(x) {
            bit_num++;
            if(bit_num == INT_BIT) {
                if(flag == 0) {
                    if(temp > MAX_INT/10)
                        return 0;
                    else if(temp == MAX_INT/10 && (x > (MAX_INT- temp*10)))
                        return 0;
                } else {
                    if(temp< MIN_INT/10)
                        return 0;
                    else if(temp == MIN_INT/10 && (x < (MIN_INT - temp *10)))
                        return 0;
                }
            }
            temp = x%10 + temp*10;
            x = x/10;
        }
       
        return temp;
    }
};
