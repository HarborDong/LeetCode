class Solution {
public:
    int findMinHelper(vector<int>& nums, int left, int right) {
        int middle = (left + right)/2;
        
        if(nums[left] <= nums[right]) {
            return nums[left];
        } else if(right == left + 1) {
            return nums[right];   
        } else {
            if(nums[left] > nums[middle]) {
               return findMinHelper(nums, left, middle);
            } else if(nums[middle] > nums[right]) {
               return findMinHelper(nums, middle, right);
            }
        }
    }
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size > 0)
            return findMinHelper(nums, 0, size - 1);
        else
            return 0;
    }
};
