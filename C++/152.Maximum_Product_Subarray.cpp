class Solution {
public:
    /**
     * 如果最大乘积子数组的最后一个索引为i
     * 那么这个最大的乘积肯定是有前一个子数组的最大值或者最小值相乘得到
     */
    int maxProduct(vector<int>& nums) {
        int result = 0, max = 0, min = 0, temp = 0;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        result = nums[0] ; max = result; min = result;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                temp = max;
                if(nums[i] * min < nums[i])
                    max = nums[i];
                else
                    max = nums[i] * min;
                if(nums[i] * temp > nums[i])
                    min = nums[i];
                else
                    min = nums[i] * temp;
            } else if(nums[i] > 0) {
                if(nums[i] * max > nums[i])
                    max = nums[i] * max;
                else 
                    max = nums[i];
                if(nums[i] * min < nums[i])
                    min = nums[i] * min;
                else
                    min = nums[i];
            } else {
                max = min = 0;
            }
            if(result < max)
                result = max;
        }
        return result;
    }
};
