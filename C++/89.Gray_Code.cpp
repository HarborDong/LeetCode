class Solution {
public:
    void greyCodeHelper(vector<int> &ret, int n) {
        int size = 0, offset = 0;
        if(n == 0) { 
            ret.push_back(0);
            return;
        }
        greyCodeHelper(ret, n - 1);
        size = ret.size();
        offset = pow(2, n - 1);

        for(; size > 0; ) {
            ret.push_back(ret[--size] + offset);
        }
        return;
    }
    vector<int> grayCode(int n) {
        vector<int> ret;
        greyCodeHelper(ret, n);
        return ret;
    }
};
