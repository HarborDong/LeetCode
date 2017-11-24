class Solution {
public:
    bool isPalindrome(int x) {
        int temp = 0, temp1 = x;
        if(x < 0 || (x%10 == 0 && x != 0))
            return false;
        if(x <  10)
            return true;
        
        while(temp1 > temp) {
            temp = temp * 10 + temp1 % 10;
            temp1 = temp1/10;
        }
        
        return (temp1 == temp || (temp1 == temp/10));
    }
};
