class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0, middle = 0, end = 0;
        int col = 0, row = 0, rowIndex = 0, colIndex = 0;
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
        col = matrix[0].size(); row = matrix.size();
        end = col * row - 1;
        
        while(end >= start) {
            middle = (start + end) / 2;
            rowIndex = middle / col;  colIndex = middle % col;  
            if(matrix[rowIndex][colIndex] == target) {
                return true;
            } else if(matrix[rowIndex][colIndex] > target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return false;
    }
};
