class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int index = 0;
        int size = 0, maxSize = 0;
        heights.push_back(0);
        while(index < heights.size()) {
            if(stk.size() == 0 || heights[stk.top()] <= heights[index]) {
                stk.push(index);
                index++;
            } else {
                int height = heights[stk.top()];
                stk.pop();
                if(stk.size() == 0) {
                    size = height * index;
                } else {
                    size = height * (index - stk.top() - 1);
                }
                if(size > maxSize) maxSize = size;
            }
        }
        return maxSize;
    }
};
