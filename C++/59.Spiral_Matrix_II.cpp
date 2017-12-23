class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        int rowStart, rowEnd;
        int colStart, colEnd;
        int totalSize, i = 0, x = 0, y = 0, traceType = 1;
        bool add = true;
        if(n == 0) return ret;
        while(i < n) {
            vector<int> temp(n, 0);
            ret.push_back(temp);
            i++;
        }       
        
        rowStart = 0, rowEnd = n - 1;
        colStart = 0, colEnd = n - 1;
        totalSize = n * n;
        i = 0;
        
        while(i < totalSize) {
            i++, ret[x][y] = i;
            switch (traceType) {
                case 1:
                    if(y < colEnd) y++;
                    if(y == colEnd) rowStart++, traceType = 2;
                    break;
                case 2:
                    if(x < rowEnd) x++;
                    if(x == rowEnd) colEnd--, traceType = 3;
                    break;
                case 3:
                    if(y > colStart) y--;
                    if(y == colStart) rowEnd--, traceType = 4;
                    break;
                case 4:
                    if(x > rowStart) x--;
                    if(x == rowStart) colStart++, traceType = 1;
                    break;
            }
        }
        return ret;  
    }
};
