class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char x = board[i][j];
                    board[i][j] = '*';
                    if (exist2(board, word, 1, i, j)) return true;
                    board[i][j] = x;
                }
            }
        }
        return false;
    }
    
    bool exist2(vector<vector<char>>& board, string word, int index, int a, int b) {
        if (index == word.size()) return true;
        else {
            char tmp = board[a][b];
            board[a][b] = '*';
            if (a + 1 != board.size() && board[a + 1][b] == word[index] && board[a + 1][b] != '*') {
                if(exist2(board, word, index + 1, a + 1, b)) return true; 
            }
            if (a != 0 && board[a - 1][b] == word[index] && board[a - 1][b] != '*') {
                if(exist2(board, word, index + 1, a - 1, b)) return true; 
            }
            if (b + 1 != board[0].size() && board[a][b + 1] == word[index] && board[a][b + 1] != '*') {
                if(exist2(board, word, index + 1, a, b + 1)) return true; 
            }
            if (b != 0 && board[a][b - 1] == word[index] && board[a][b - 1] != '*') {
                if(exist2(board, word, index + 1, a, b - 1)) return true; 
            }
            board[a][b] = tmp;
            return false;
        }
    }
};