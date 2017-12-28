class Solution {
public:
/* Binary Search method
    int mySqrt(int x) {
        int rangeStart = x, rangeEnd = x;
        if(x <= 1) return x;
        while(rangeStart > x / rangeStart) {
            rangeEnd = rangeStart;
            rangeStart /= 2;
        }

        while(1) {
            int middle = (rangeEnd + rangeStart) / 2;
            unsigned int temp = middle * middle;
            //cout << rangeStart << " " <<  rangeEnd <<" "<< temp <<endl;
            if(temp > x) {
                rangeEnd =  middle;
            } else {
                rangeStart = middle;
            }
            temp = (rangeStart + 1) * (rangeStart + 1);
            if (temp > x)
                break;
        }
        return rangeStart;
    }
*/
/*
 * Newton-Raphson method
 */
    int mySqrt(int x) {  
        if (x <= 1)  
            return x;  
        double pre;  
        double cur = x/2;  
        do  
        {  
            cur = x / (2 * cur) + cur / 2.0;  
        } while ((cur*cur - x) > 0.01);  
        return int(cur);  
    } 
};
