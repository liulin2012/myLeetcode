class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < col; i++) {
            if (board[0][i] == 'O')
                {board[0][i] = '1'; DFS(board, 0, i);}
            if (board[row - 1][i] == 'O')
                {board[row - 1][i] = '1'; DFS(board, row - 1, i);}
        }
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                {board[i][0] = '1'; DFS(board, i, 0);}
            if (board[i][col - 1] == 'O')
                {board[i][col - 1] = '1'; DFS(board, i, col - 1);}
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
    
    void BFS(vector<vector<char>>& board, int row, int col) {
        queue<pair<int,int>> q;
        q.push({row, col});
        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if (row > 1 && board[row - 1][col] == 'O')
                {board[row - 1][col] = '1'; q.push({row - 1, col});}
            if (col > 1 && board[row][col - 1] == 'O')
                {board[row][col - 1] = '1'; q.push({row, col - 1});}
            if ((row + 2) < board.size() && board[row + 1][col] == 'O')
                {board[row + 1][col] = '1'; q.push({row + 1, col});}
            if ((col + 2) < board[0].size() && board[row][col + 1] == 'O')
                {board[row][col + 1] = '1'; q.push({row, col + 1});}
        }
    }
    
    void DFS(vector<vector<char>>& board, int row, int col) {
        board[row][col] = '1';
        if (row > 1 && board[row - 1][col] == 'O')
            DFS(board, row - 1, col);
        if (col > 1 && board[row][col - 1] == 'O')
            DFS(board, row, col - 1);
        if ((row + 2) < board.size() && board[row + 1][col] == 'O')
            DFS(board, row + 1, col);
        if ((col + 2) < board[0].size() && board[row][col + 1] == 'O')
            DFS(board, row, col + 1);
    }
};