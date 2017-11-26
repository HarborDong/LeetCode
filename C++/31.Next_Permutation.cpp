class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last_ascend = -1, bigger_index,temp;
        int index = nums.size() - 2;
        while(index > -1) {
            if(nums[index] < nums[index + 1]) {
                last_ascend = index;
                break;
            }
            index--;
        }

        if(index != -1) {
            index = nums.size() -1;
            while(index > last_ascend) {
                if(nums[last_ascend] < nums[index]) {
                    bigger_index = index;
                    break;
                }
                index--;
            }

            temp = nums[bigger_index];
            nums[bigger_index] = nums[last_ascend];
            nums[last_ascend] = temp;
        }
        last_ascend++;
        bigger_index = nums.size() - 1;
        while(last_ascend < bigger_index) {
            temp = nums[last_ascend];
            nums[last_ascend] = nums[bigger_index];
            nums[bigger_index] = temp;
            last_ascend++;
            bigger_index--;
        }
        return;
    }
};

