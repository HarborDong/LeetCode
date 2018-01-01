class Solution {
public:
    void subsetsHelper(vector<vector<int>> &ret, vector<int> &subset, int start, vector<int> &nums, int k) {
        if(subset.size() == k) ret.push_back(subset);     
        for(int i = start; i <= nums.size() - 1; i++) {
            subset.push_back(nums[i]);
            subsetsHelper(ret, subset, i + 1, nums, k);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        for(int i = 0; i <= nums.size(); i++) {
            subsetsHelper(ret, subset, 0, nums, i);
        }
        return ret;
    }
};
