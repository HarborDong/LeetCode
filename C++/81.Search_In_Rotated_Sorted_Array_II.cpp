class Solution {
public:
    int searchHelper(vector<int>& nums, int target, int start, int end) {
        int middle = (end + start) / 2;

        if(end < start) return -1;
        /**
         * case1 start biggest middle end
         * case2 start middle biggest end
         * sepcial case start == middle or end == middle
         */

        if(nums[start] == nums[middle] && nums[start] != nums[end]) middle = (middle + end) / 2;
        if(nums[middle] == nums[end] && nums[start] != nums[end]) middle = (start + middle) / 2;
        if(nums[start] == nums[middle] && nums[middle] == nums[end]) {
            int temp = nums[middle];
            if(target == temp) return middle;
            while(start < end && nums[start] == nums[end]) start++;
            while(start < end && nums[end] == temp) end--;
            middle = (start + end) / 2;
        }
        
        if(nums[middle] == target) {
            return middle;
        }else if(nums[middle] < target) {
            if(nums[start] <= target && nums[start] > nums[middle]) {
                return searchHelper(nums, target, start, middle - 1);
            } else {
                return searchHelper(nums, target, middle + 1, end);
            }
        } else {      
            if(nums[end] >= target && nums[end] < nums[middle]) {
                return searchHelper(nums, target, middle + 1, end);
            } else {
                return searchHelper(nums, target, start, middle - 1);
            }
        }
    }
    bool search(vector<int>& nums, int target) {
        int index = -1;
        if(nums.size() == 0) return false;
        index = searchHelper(nums, target, 0, nums.size() - 1);
        return index == -1 ? false : true;
    }
};
