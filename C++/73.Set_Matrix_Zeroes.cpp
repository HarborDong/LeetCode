class Solution {
public:
    /**
     * in order to using constant space to solution this question,
     * 1. check the first whether include zero
     * 2. record the col number which is set to 0 on the first line.
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int flag = 0, flag1 = 0;
        int rowNum = matrix.size();
        int colNum = 0;
        
        if(rowNum == 0) return;
        colNum = matrix[0].size();
        if(colNum == 0) return;
        
        for(int i = 0; i < colNum; i++) {
            if(matrix[0][i] == 0) {
                flag = 1; break;
            }
        }
        
        for(int j = 1; j < rowNum; j++) {
            for(int i = 0; i < colNum; i++) {
                if(matrix[j][i] == 0) {
                    matrix[0][i] = 0;
                    flag1 = 1;
                } 
            }
            if(flag1 == 1) {
                for(int i = 0; i < colNum; i++) matrix[j][i] = 0;
                flag1 = 0;
            }
        }
        for(int i = 0; i < colNum; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < rowNum; j++) matrix[j][i] = 0;
            }
        }
        if(flag == 1) {
            for(int i = 0; i < colNum; i++) matrix[0][i] = 0;
        }
        return;
    }
};
