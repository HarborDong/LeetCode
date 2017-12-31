class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redNum = 0, whiteNum = 0, blueNum = 0;
        int size = nums.size();
        if(size == 0) return;
        for(int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                redNum++;
            } else if(nums[i] == 1) {
                whiteNum++;
            } else {
                blueNum++;
            }
        }
        for(int i = 0; i < redNum; i++) nums[i] = 0;
        for(int i = 0; i < whiteNum; i++) nums[i + redNum] = 1;
        for(int i = 0; i < blueNum; i++) nums[i + redNum + whiteNum] = 2;
        
        return;
    }
};
