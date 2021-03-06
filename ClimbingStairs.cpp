/*
 * Climbing Stairs 
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int result[n];
        result[0] = 1;
        result[1] = 2;
        for (int i = 2; i < n; i++){
            result[i] = result[i - 1] + result[i - 2];
        }
        return result[n - 1];
    }
};

int climbStairs(int n) {
    if (n == 1) return 1;
    int temp1 = 1;
    int temp2 = 2;
    for (int i = 3; i <= n; ++i) {
        int temp = temp2;
        temp2 = temp1 + temp2;
        temp1 = temp;
    }
    return temp2;
}