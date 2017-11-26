class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size(), head_index = 0, change_index = 0; 
        while (head_index < length) {
            if(nums[head_index] != val)
                nums[change_index++] = nums[head_index];
            head_index++;
        }
        return change_index;
    }
};
