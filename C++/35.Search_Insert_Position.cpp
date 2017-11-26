class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int position = 0, right = nums.size() - 1, middle = 0;
        if(nums.size() == 0) return position;
        while(position <= right) {
            middle = (position + right) / 2;
            if(target <= nums[middle]) {
                right = middle - 1;
            } else {
                position = middle + 1;
            }
        }

        return position;
    }
};
