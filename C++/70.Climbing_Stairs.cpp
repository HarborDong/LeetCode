class Solution {
public:
    /**
     * step(n) is used to describe the number of way to climb to the top N
     * The transformation equation : step(n) = step(n-1) + step(n-2) 
     */
    int climbStairs(int n) {
        int step1 = 1, step2 = 1;
        int ret = 0;
        if(n <= 1) return n;
        for(int i = 2; i <= n; i++) {
            ret = step1 + step2;
            step1 = step2;
            step2 = ret;
        }
        return ret;
    }
};
