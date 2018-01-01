class Solution {
public:
    void combineHelper(vector<vector<int>> &ret, vector<int> &combine, int start, int n, int k) {
        if(combine.size() == k) ret.push_back(combine);
        
        for(int i = start; i <= n; i++) {
            combine.push_back(i);
            combineHelper(ret, combine, i + 1, n, k);
            combine.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> element;
        combineHelper(ret, element, 1, n , k);
        return ret;
    }
};
