class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator changePoint = nums.begin(), headPoint = nums.begin();
        int times = 0;
        while(headPoint < nums.end()) {
            if(headPoint + 1 < nums.end() && (*headPoint == *(headPoint + 1))) {
                times++;
            } else {
                times = 0;
            }
            if(times < 2) {
                *changePoint = *headPoint;
                changePoint++;
            }
            headPoint++;
        }
        if(changePoint < nums.end())
            nums.erase(changePoint, nums.end());
        return nums.size();
    }
};
