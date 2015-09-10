class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        BFS(n, 0, 0, res, "");
        return res;
    }
    
    void BFS(int n, int left, int right, vector<string>& res, string one) {
        if (left == n && right == n) res.push_back(one);
        else {
            if (n > left) BFS(n, left + 1, right, res, one + "(");
            if (right < left) BFS(n, left , right + 1, res, one + ")");
        }
    }
};