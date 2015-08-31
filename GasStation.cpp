class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int amount = gas.size();
        int need = 0, left = 0, start = 0;
        for (int i = 0; i < amount; i++) {
            if (left + gas[i] >= cost[i]) 
                left += gas[i] - cost[i];
            else 
                need += left + gas[i] - cost[i], left = 0, start = i + 1;
        }
        return left + need >= 0 ? start : -1;
    }
};