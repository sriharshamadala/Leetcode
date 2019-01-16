class Solution {
public:
    bool isValidWord (vector<vector<char>>& board, string word, int word_index, int row, int col, vector<vector<bool>> bool_board) {
        if (word_index >= word.length() - 1) {
            return true;
        }
        
        // check left
        if ((col > 0) && (!bool_board[row][col - 1]) && (board[row][col - 1] == word[word_index + 1])) {
            bool_board[row][col - 1] = true;
            if (isValidWord(board, word, word_index + 1, row, col - 1, bool_board)) {
                return true;
            }
            bool_board[row][col - 1] = false;
        }
        
        // check right
        if ((col < board[0].size() - 1) && (!bool_board[row][col + 1]) && (board[row][col + 1] == word[word_index + 1])) {
            bool_board[row][col + 1] = true;
            if (isValidWord(board, word, word_index + 1, row, col + 1, bool_board)) {
                return true;
            }
            bool_board[row][col + 1] = false;
        }
        
        // check down
        if ((row < board.size() - 1) && (!bool_board[row + 1][col]) && (board[row + 1][col] == word[word_index + 1])) {
            bool_board[row + 1][col] = true;
            if (isValidWord(board, word, word_index + 1, row + 1, col, bool_board)) {
                return true;
            }
            bool_board[row + 1][col] = false;
        }
        
        // check up
        if ((row > 0) && (!bool_board[row - 1][col]) && (board[row - 1][col] == word[word_index + 1])) {
            bool_board[row - 1][col] = true;
            if (isValidWord(board, word, word_index + 1, row - 1, col, bool_board)) {
                return true;
            }
            bool_board[row - 1][col] = false;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if (board.size() == 0) return false;
        
        vector<vector<bool>> bool_board(board.size(), vector<bool>(board[0].size(), false));
        
        int word_index = 0;
        for (int ii = 0; ii < board.size(); ++ii) {
            for (int jj = 0; jj < board[0].size(); ++jj) {
                if (board[ii][jj] == word[word_index]) {
                    bool_board[ii][jj] = true;
                    if (isValidWord(board, word, word_index, ii, jj, bool_board)) {
                        return true;
                    }
                    bool_board[ii][jj] = false;
                }
            }
        }
        
       return false;
    }
};