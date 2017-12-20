class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rowStart, rowEnd;
        int colStart, colEnd;
        int totalSize, i = 0, x = 0, y = 0, traceType = 1;
        bool add = true;
        if(matrix.size() == 0) return ret;
        if(matrix[0].size() == 0) return ret;
        
        rowStart = 0, rowEnd = matrix.size() - 1;
        colStart = 0, colEnd = matrix[0].size() - 1;
        totalSize = matrix.size() * matrix[0].size();
        
        while(i < totalSize) {
            if(add) ret.push_back(matrix[x][y]), add = false, i++;
            switch (traceType) {
                case 1:
                    if(y < colEnd) y++, add = true;
                    if(y == colEnd) rowStart++, traceType = 2;
                    break;
                case 2:
                    if(x < rowEnd) x++, add = true;
                    if(x == rowEnd) colEnd--, traceType = 3;
                    break;
                case 3:
                    if(y > colStart) y--, add = true;
                    if(y == colStart) rowEnd--, traceType = 4;
                    break;
                case 4:
                    if(x > rowStart) x--, add = true;
                    if(x == rowStart) colStart++, traceType = 1;
                    break;
            }
        }
        return ret;
    }
};
