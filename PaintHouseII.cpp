class Solution {
public:
    
    struct Position {
    int index;
    int value;
    Position (int _i, int _v) : index (_i), value (_v) {}
};

//(nk) time O(1) auxiliary space;
int minCostII (vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) {
        return 0;
    }

    //I think it's better to return 0 when painting 
    //more than 1 houses with a single color;
    int k = costs[0].size();
    if (k == 1) {
        return n == 1 ? costs[0][0] : 0;
    }

    Position min1 (-1, 0), min2 (-1, 0);
    for (int i = 0; i < n; i++) {
        Position tmp1 = min1, tmp2 = min2;
        min1.value = INT_MAX;
        min2.value = INT_MAX;
        for (int j = 0; j < k; j++) {
            int cost = (j != tmp1.index ? tmp1.value : tmp2.value) + costs[i][j];

            //update the min1 and min2 of the current row;
            if (cost < min1.value) {
                min2 = min1;
                min1 = Position (j, cost);
            } else if (cost < min2.value) {
                min2 = Position (j, cost);
            }
        }
    }

    return min1.value;
}
};