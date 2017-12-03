class Solution {
public:
    bool combinationSum2Helper(vector<int> &candidates, int begin,
                               vector<vector<int>>& result, 
                               vector<int> &resolve, int target) {
        if(target == 0) {
            if(resolve.size()) result.push_back(resolve);
            return true;
        }
        //if(begin == candidates.size()) return false;
        
        for(int i = begin; i < candidates.size(); i++) {
            if(candidates[i] > target) return false;
            resolve.push_back(candidates[i]);
            combinationSum2Helper(candidates, i + 1, result, resolve,
                                  target - candidates[i]);
            resolve.pop_back();
            while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                i++;
        }
        return true;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> resolve;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, 0, result, resolve, target);
        return result;
    }
};
