/*
 * 1.max area must include the max of (i,ai), the right or left of max area don't include the line which is longer than the
 * the border of max area;
 * (Reduction to Absurdity)：if longest line is out of max area, we will have new max area. that is contradiction to the old 
 * max area. for example:
 *  |longest          |longer
 *  |   |maxarea|     |
 *  |   |       |     |
 * -------------------------------
 * so we can use squeeze method to fix this question
 * two pointer, one is from starter, the other is from the ender.
 * p_left & p_right, *p_left < *p_right, p_left shift rightforward,vice versa.
 * when p_left shift, if *p_left_old < *p_left_new, calculate area's size, can compare with *p_right.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> :: iterator start = height.begin();
        vector<int> :: iterator end = height.end() - 1;
#define MIN(a, b) (((*a) < (*b)) ? (*a) : (*b))
        int max_size = 0;
        
        while(start < end)
        {
            if((end- start)* MIN(start, end) > max_size) {
                max_size = (end- start)* MIN(start, end);
            }
            
            if(*start > *end) {
                max_size = (end- start)*(*end);
                *end--;
            } else if(*end > *start) {
                *start++;
            } else {
                *end--;
                *start++;
            }
        }
        return max_size;
    }
};
