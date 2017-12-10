class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<int>::iterator startIndex, vector<vector<int>>& res) {
        vector<int>::iterator index =startIndex, i;
        int temp = 0;
        if(startIndex == nums.end() - 1) {
            res.push_back(nums);
            return;
	}
        
        for(index = startIndex; index < nums.end(); index++) {
            //if(index != startIndex && *index == temp) continue;
            temp= *index;
            for(i = index; i > startIndex; i--) {
                *i = *(i-1);
            }
            *startIndex = temp;
            permuteHelper(nums, startIndex + 1, res);
            temp= *startIndex;
            for(i = startIndex; i < index; i++) {
                *i = *(i+1);
            }
            *index = temp;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteHelper(nums, nums.begin(), res);
        return res;
    }
};
