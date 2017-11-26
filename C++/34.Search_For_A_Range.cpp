class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.size() == 0) return result;
        int left_range = -1, right_range = -1;
        int left = 0, right = nums.size()-1 ,middle;
        left_range = left;
        while(left_range <= right) {
            middle = (left_range + right)/2;
            if(target <= nums[middle]) {
                right = middle - 1;
            } else {
                left_range = middle + 1;
            }
        }
        if(nums[left_range] != target || left_range > nums.size() - 1) return result;
        right_range = nums.size() - 1;
        while(left <= right_range) {
            middle = (left + right_range)/2;
            if(target >= nums[middle]) {
                left = middle + 1;
            } else {
                right_range = middle - 1;
            }
        }

        result[0] = left_range;
        result[1] = right_range;
        return result;
    }
};
