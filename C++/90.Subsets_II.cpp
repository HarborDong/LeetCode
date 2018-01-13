class Solution {
public:
    void subsetsWithDupHelper(vector<vector<int>> &ret, vector<int> &nums, vector<int> &element, int start) {
        ret.push_back(element);
        if(start == nums.size()) return;       
        for (int i = start; i < nums.size(); i++) {
            element.push_back(nums[i]);
            subsetsWithDupHelper(ret, nums, element, i + 1);
            element.pop_back();
            while((i + 1) < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> element;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(ret, nums, element, 0);
        return ret;
    }
};
