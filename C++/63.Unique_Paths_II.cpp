class Solution {
public:
    /**
     * we use path(A->B) to indicate the number of unique path from A to B; 
     * The transformation equation :
     *          path(A->B) = path(A->C) + path(A->D);
     * if C is obstacle, then path(A->C) = 0
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;
        
        int step[m][n];
        step[0][0] = 1 - obstacleGrid[0][0];
        for(int i = 1; i < n; i++) {
            step[0][i] = obstacleGrid[0][i] ? 0 : step[0][i-1];
        }
        for(int i = 1; i < m; i++) {
            step[i][0] = obstacleGrid[i][0] ? 0 : step[i-1][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                step[i][j] = obstacleGrid[i][j] ? 0 : (step[i-1][j] + step[i][j-1]); 
            }
        }
        return step[m-1][n-1];
    }
};
