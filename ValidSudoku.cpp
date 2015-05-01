class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            int a[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (a[board[i][j] - '0'] == 0) a[board[i][j] - '0'] = 1;
                    else return false;
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            int a[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (a[board[j][i] - '0'] == 0) a[board[j][i] - '0'] = 1;
                    else return false;
                }
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int a[10] = {0};
                for (int m = 0; m < 3; m++)
                for (int n = 0; n < 3; n++)
                if (board[i+m][j+n] != '.') {
                    if (a[board[i+m][j+n] - '0'] == 0) a[board[i+m][j+n] - '0'] = 1;
                    else return false;
                }
            }
        }
        
        return true;
        
    }
};