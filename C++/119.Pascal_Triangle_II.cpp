class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i = 2;
        vector<int> ret(rowIndex + 1, 1);
        if(rowIndex > 1){
            while(i <= rowIndex) {
                int j = i - 1;
                while(j > 0) {
                    ret[j] += ret[j - 1];
                    j--;
                }
                i++;
            }
        }
        return ret;
    }
};
