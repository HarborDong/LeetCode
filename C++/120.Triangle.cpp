class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(), j = 0;
        if(size == 0) return 0;
        vector<int> result(*(triangle.end()-1));
        size--;
        while (size > 0) {
            size--;
            j = 0;
            while(j <= size) {
                result[j] = min(result[j], result[j + 1]) + triangle[size][j];
                j++;
            }
        }
        return result[0];
    }
};
