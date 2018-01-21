class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i = 0;
        vector<vector<int>> ret;
        while(i < numRows) {
            vector<int> element;
            int j = 1;
            element.push_back(1);
            while(j < i) {
                element.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
                j++;
            }
            if(j == i) element.push_back(1);
            ret.push_back(element);
            i++;
        }
        return ret;
    }
};
