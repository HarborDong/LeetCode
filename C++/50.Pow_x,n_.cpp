class Solution {
public:
    double myPow(double x, int n) {
        double temp = 0.0;
        if(x == 0.0) return 0.0;
        if(n == 0) {
            return 1.0;
        } else if (n == 1) {
            return x;   
        } else if (n < 0) {
        /*
         * In order to avoiding ABS of min_int isn't exist.
         * we must change 1/(x^(-n)) to x^(-1) * 1/(x^(-(n+1))
         */
          return 1/x * myPow(1/x, -(n + 1));  
        } else {
            temp =  myPow(x, n/2) ;
            temp *= temp;
            if(n % 2) {
                temp = temp * myPow(x, 1);
            }
            return temp;
        } 
    }
};
