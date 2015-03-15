/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *    1         3     3      2      1
 *        \       /     /      / \      \
 *             3     2     1      1   3      2
 *                 /     /       \                 \
 *                    2     1         2                 3
 *
 */

class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        int result[n + 1] = {};
        result[0] = result[1] = 1;
        for (int i = 2; i < n + 1; i++){
            result[i] = 0;
            for (int j = 0; j < i; j++)
                result[i] += result[j] * result[i - j - 1];
        }
        return result[n];
    }
};