class Solution {
public:
    /*
    void rotate(vector<vector<int>>& matrix) {
        int widSize = matrix.size(), lenSize = matrix[0].size();
        int m = 0, n = 0, i = 0, temp,temp1,x,y;
        int sizeMin = lenSize > widSize ? widSize : lenSize;
        int widBase = lenSize > widSize ? 0 : widSize -lenSize;
        int n_end = widBase, n_start =  widSize - 1;
        for(m = 0; m < sizeMin/2; m++, n_start--, n_end++) {
            for(n = n_start; n > n_end; n--){
                y = m; x = n;
                temp = matrix[x][y];
                for(i = 0; i < 4; i++) {
                    temp1 = y + widBase;
                    y = widSize - 1 - x;
                    x = temp1;
                    temp1 = matrix[x][y];
                    matrix[x][y] = temp;
                    temp = temp1;                        
                }
            }
        }

        if(lenSize > widSize) {
            for(m = widSize; m < lenSize; m++){
                vector<int> addVec;
                for(n = widSize - 1; n > -1; n--) {
                    addVec.push_back(matrix[n][m]);
                }
                matrix.push_back(addVec);
            }
            for(n = 0; n < widSize; n++) {
                matrix[n].erase(matrix[n].end() -(lenSize - widSize), matrix[n].end());
            }
        } else if(lenSize < widSize) {
            for(m = widBase - 1; m > -1; m--){
                for(n = widBase; n < widSize; n++){
                    matrix[n].push_back(matrix[m][n-widBase]);
                }
            }
            matrix.erase(matrix.begin(), matrix.begin() + widBase);
        }
        return;        
    }*/

public:
    void rotate(vector<vector<int>>& matrix) {
        
        reverse(matrix.begin(), matrix.end());
        for(int i = 0;i < matrix.size(); i++){
            for(int j = i + 1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return;
    }
};
