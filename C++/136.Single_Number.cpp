class Solution {
public:
    /**
     * 谨记异或的特性:
     * a^a = 0
     *
     */
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};
