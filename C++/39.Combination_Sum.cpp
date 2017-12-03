class Solution {
public:
    bool combinationSumHelper(vector<vector<int>>& result, vector<int> &resolve, 
                              vector<int>& candidates, vector<int>::size_type index,
                              int target) {
        
        if(target == 0) {
            if(resolve.size())
                result.push_back(resolve);
            return true;
        }

        if(index == candidates.size() || candidates[index] > target) return false;
        
        resolve.push_back(candidates[index]);
        combinationSumHelper(result, resolve, candidates, index,
		       	     target - candidates[index]);
        resolve.pop_back();
        combinationSumHelper(result, resolve, candidates, index + 1, target);
        return true;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> resolve;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(result, resolve, candidates, 0, target);
        return result;
    }
};
