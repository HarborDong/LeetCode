class Solution {
    /*
     * when nums[i] is the ending of subarray,
     * if we want to get the max sum(max_sum[i]) of this subarray which include nums[i]，
     * max_sum[i] = max(max_sum[i - 1], 0) + nums[i]
     */
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxValue = 0, sum = 0;
        maxValue = nums[0];
        sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum = sum >= 0 ? (sum + nums[i]) : nums[i];
            if(maxValue < sum) {
                maxValue = sum;
            }
        }
        return maxValue;
    }
};
