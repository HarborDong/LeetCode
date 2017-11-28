class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int index = 0, i = 0, j = 0, k = 0, bit_index = 0;
        vector<bitset<9>> row(9, 0), col(9, 0), block(9, 0);
        
        for(; index < board.size() * board.size(); index++) {
            i = index / board.size(); j = index % board.size(); k = i / 3 * 3 + j / 3;
            
            if(board[i][j] == '.') {
                continue;
            } else {
                bit_index = board[i][j] - '1';
                if(row[i][bit_index] | col[j][bit_index] | block[k][bit_index]) {
                    return false;
                } else {
                    row[i].set(bit_index);
                    col[j].set(bit_index);
                    block[k].set(bit_index);
                }
            }
        }
        return true;        
    }
};
