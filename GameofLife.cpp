class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        vector<vector<int>> res(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 0) {
                    int count = 0;
                    if (i != 0 && board[i-1][j] == 1) count++;
                    if (j != 0 && board[i][j-1] == 1) count++;
                    if (i != board.size() - 1 && board[i+1][j] == 1) count++;
                    if (j != board[0].size() - 1 && board[i][j+1] == 1) count++;
                    if (i != 0 && j != 0 && board[i-1][j-1] == 1) count++;
                    if (i != board.size() - 1 && j != board[0].size() - 1 && board[i+1][j+1] == 1) count++;
                    if (i != 0 && j != board[0].size() - 1 && board[i-1][j+1] == 1) count++;
                    if (j != 0 && i != board.size() - 1 && board[i+1][j-1] == 1) count++;
                    
                    if (count == 3) res[i][j] = 1;
                } else {
                    int count = 0;
                    if (i != 0 && board[i-1][j] == 1) count++;
                    if (j != 0 && board[i][j-1] == 1) count++;
                    if (i != board.size() - 1 && board[i+1][j] == 1) count++;
                    if (j != board[0].size() - 1 && board[i][j+1] == 1) count++;
                    if (i != 0 && j != 0 && board[i-1][j-1] == 1) count++;
                    if (i != board.size() - 1 && j != board[0].size() - 1 && board[i+1][j+1] == 1) count++;
                    if (i != 0 && j != board[0].size() - 1 && board[i-1][j+1] == 1) count++;
                    if (j != 0 && i != board.size() - 1 && board[i+1][j-1] == 1) count++;
                    
                    if (count == 2 ||  count == 3) res[i][j] = 1;
                    else res[i][j] = 0;
                }
            }
            
        board = res;
    }
};