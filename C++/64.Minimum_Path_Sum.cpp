class Solution {
public:
    /**
     * we use min(A->B) to indicate the sum of number from A to B; 
     * The transformation equation :
     *          min(A->B) = min(A->C) + min(A->D);
     */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        
        int sum[m][n];
        sum[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            sum[0][i] = grid[0][i] + sum[0][i-1];
        }
        for(int i = 1; i < m; i++) {
            sum[i][0] = grid[i][0] + sum[i-1][0];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                sum[i][j] = grid[i][j] + (sum[i-1][j] > sum[i][j-1] ? sum[i][j-1] : sum[i-1][j]); 
            }
        }
        return sum[m-1][n-1];       
    }
};
