class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int result = 0;
        int maxEnd = 0;
        int minPoint = prices[0];
        for (int i = 1; i < prices.size(); i++){
            minPoint = min(minPoint, prices[i]);
            maxEnd = prices[i] - minPoint;
            result = max(result, maxEnd);
        }
        
        return result;
    }
};