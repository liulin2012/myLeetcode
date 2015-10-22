class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) 
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == '1')
                    matrix[i][j] = matrix[i][j - 1] + 1;
                    
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = 0; j < matrix.size() - result; j++) {
                if ((matrix[j][i]-'0') > result) {
                    int nums = matrix[j][i] - '0';
                    while (nums > result) {
                        int tmp = j;
                        int count = 0;
                        for (int m = 0; m < nums; m++) {
                            if (tmp == matrix.size()) break;
                            else if ((matrix[tmp++][i]-'0') >= nums) count++;
                            else break;
                        }
                        result = max(result, count);
                        if (result == nums) break;
                        else nums--;
                    }
                }
                
            }
        }
        
        return result*result;
            
    }
};


int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0; 
            pre = temp;
        }
    }
    return maxsize * maxsize;
}