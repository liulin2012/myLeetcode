class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        DFS(board, 0, 0, used1, used2, used3);
        
    }
    
    bool DFS(vector<vector<char>>& board, int a, int b, int used1[9][9], int used2[9][9], int used3[9][9]) {
        if (a == board.size()) return true;
        else if (board[a][b] == '.') {
            int k = a / 3 * 3 + b / 3;
            for (int i = 0; i < 9; i++) {
                if (used1[a][i] || used2[b][i] || used3[k][i]) continue;
                board[a][b] = i + 1 + '0';
                used1[a][i] = used2[b][i] = used3[k][i] = 1;
                int m = a, n = b;
                if (n == 8) {m++; n = -1;}
                if (DFS(board, m, n+1, used1, used2, used3)) return true;
                used1[a][i] = used2[b][i] = used3[k][i] = 0;
            }
            board[a][b] = '.';
            return false;
        } else {
            if (b == 8) {a++; b = -1;}
            return DFS(board, a, b+1, used1, used2, used3);
        }
    }
};