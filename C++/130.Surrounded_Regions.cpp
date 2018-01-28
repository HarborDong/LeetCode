class Solution {
public:
    void sloveHelper(vector<vector<char>>& board, int x , int y) {
        if(board[x][y] != 'O') return;
        if(board[x][y] == 'O') {
            board[x][y] = '#';
            if((x - 1) >= 0 && board[x - 1][y] == 'O') {
                sloveHelper(board, x - 1, y);
            }
            if((x + 1) < board.size() && board[x + 1][y] == 'O') {
                sloveHelper(board, x + 1, y);
            }
            if((y - 1) >= 0 && board[x][y - 1] == 'O') {
                sloveHelper(board, x, y - 1);
            }
            if((y + 1) < board[0].size() && board[x][y + 1] == 'O') {
                sloveHelper(board, x, y + 1);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<vector<int>> index;
        if(board.size() == 0) return;
        if(board[0].size() == 0) return;
        int row = board.size() - 1;
        int col = board[0].size() - 1;
        for(int i = 0; i < board[0].size(); i++) {
            if(board[0][i] == 'O') {
                sloveHelper(board, 0, i);
            }
            if(board[row][i] == 'O') {
                sloveHelper(board, row, i);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') {
                sloveHelper(board, i, 0);
            }
            if(board[i][col] == 'O') {
                sloveHelper(board, i, col);
            } 
        }
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        return;
    }
};
