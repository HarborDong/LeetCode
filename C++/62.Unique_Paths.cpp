class Solution {
public:
    /**
     * we use path(A->B) to indicate the number of unique path from A to B; 
     * The transformation equation :
     *          path(A->B) = path(A->C) + path(A->D);
     */
    int uniquePaths(int m, int n) {
        if(m < 1 || n < 1) return 0;
        int step[m][n];
        for(int i = 0; i < n; i++) {
            step[0][i] = 1;
        }
        for(int i = 0; i < m; i++) {
            step[i][0] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                step[i][j] = step[i][j-1] + step[i-1][j];
            }
        }
        return step[m-1][n-1];
    }
};
