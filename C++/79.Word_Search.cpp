class Solution {
public:
    bool existHelper(vector<vector<char>>& board, string &word, int x, int y, int pos) {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        
        if(board[x][y] != word[pos]) {
            return false;
        } else {
            if(pos == word.length() - 1) return true;
            char temp = board[x][y];
            board[x][y] = 0;
            if(existHelper(board, word, x - 1, y, pos + 1))
                return true;
            if(existHelper(board, word, x + 1, y, pos + 1))
                return true;            
            if(existHelper(board, word, x, y - 1, pos + 1))
                return true;
            if(existHelper(board, word, x, y + 1, pos + 1))
                return true;
            board[x][y] = temp;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(existHelper(board, word, i, j, 0))
                    return true;
        return false;
    }
};
