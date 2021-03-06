Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 1 || prices.size() == 0) return 0;
        int result = 0;
        int past = *prices.begin();
        auto iter = prices.begin();
        for (iter++; iter != prices.end(); iter++)
        {
            if (*iter > past) result += *iter - past;
            past = *iter;
        }
        return result;
    }
};