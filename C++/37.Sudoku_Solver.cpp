class Solution {
public:
    bool solveSudokuHelper(vector<vector<char>>& board, vector<bitset<9>>& row,
                           vector<bitset<9>>& col, vector<bitset<9>>& block,
                           int index)
    {
        int i = index/board.size(), j = index % board.size();
        int choose = 0;

        if(index == board.size() * board.size()) return true;
        
        if(board[i][j] != '.') {
            return solveSudokuHelper(board, row, col, block, index + 1);
        } else {
            for(choose = 0; choose < board.size(); choose++) {
                if(row[i][choose] | col[j][choose] | block[i/3*3 + j/3][choose]) {
                    continue;
                }
                board[i][j] = '1' + choose;
                row[i].set(choose);
                col[j].set(choose);
                block[i/3*3 + j/3].set(choose);
                if(!solveSudokuHelper(board, row, col, block, index + 1)) {
                    row[i].reset(choose);
                    col[j].reset(choose);
                    block[i/3*3 + j/3].reset(choose);
                    board[i][j] = '.';
                } else {
                    return true;
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> row(9,0), col(9,0), block(9,0);
        int size = board.size() * board.size(), index = 0, i = 0, j = 0;
        while(index < size) {
            i = index / board[0].size(); j = index % board[0].size(); 

            if(board[i][j] != '.') {
                row[i].set(board[i][j] - '1');
                col[j].set(board[i][j] - '1');
                block[i/3*3 + j/3].set(board[i][j] - '1');
            }
            index++;
        }

        solveSudokuHelper(board, row, col, block, 0);
        return;
    }
};
