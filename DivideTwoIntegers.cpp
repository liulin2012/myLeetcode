class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long dd = labs(dividend);
        long ds = labs(divisor);
        long res = 0;
        while (dd >= ds) {
            long tmp = ds;
            long multy = 1;
            while ((tmp << 1) <= dd) {
                tmp <<= 1;
                multy <<= 1;
            }
            dd -= tmp;
            res += multy;
        }
        return sign*res;
    }
};