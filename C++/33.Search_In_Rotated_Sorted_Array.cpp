class Solution {
public:
    int searchIndex(vector<int>& nums, int left, int right, int target) {
        int middle = (left + right)/2;
        if (right < left) return -1;
        if(nums[middle] == target) {
            return middle;
        } else if(target < nums[middle])  {
            if(target >= nums[left] || nums[left] > nums[middle]){
                return searchIndex(nums, left, middle - 1, target);
            } else {
                return searchIndex(nums, middle + 1, right, target);
            }
        } else {
            if(nums[middle] > nums[right] || nums[right] >= target) {
                return searchIndex(nums, middle + 1, right, target);
            } else {
                return searchIndex(nums, left, middle -1, target);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int right = nums.size() - 1;
        return searchIndex(nums, 0, right, target);
    }
};
