class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        if (ratings.size() == 1) return 1;
        
        int res = 0;
        vector<int> index(ratings.size(), 0);
        if (ratings[0] <= ratings[1]) index[0] = 1;
        for (int i = 1; i < ratings.size()-1; i++) {
            if (ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) { index[i] = 1; continue; }
            if (ratings[i] > ratings[i-1] && ratings[i] <= ratings[i+1]) {index[i] = index[i-1]+1; continue;}
        }
        if (ratings[ratings.size()-1] <= ratings[ratings.size()-2]) index[ratings.size()-1] = 1;
        else index[ratings.size()-1] = index[ratings.size()-2] + 1;
        
        for (int i = index.size() - 1; i > 0; i--) {
            if (index[i] != 0) res += index[i];
            else {
                if (index[i-1] == 0) index[i] = index[i+1]+1;
                else if (ratings[i] == ratings[i-1]) index[i] = index[i+1] + 1;
                else index[i] = max(index[i-1], index[i+1]) + 1;
                res += index[i];
            }
        }
        if (index[0] == 0) index[0] = index[1] + 1;
        res += index[0];
        
        return res;
    }
};