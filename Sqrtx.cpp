class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long begin = 2;
        long end = x;
        while (begin < end) {
            long mid = (begin + end) / 2;
            if (mid*mid <= x) begin = mid+1;
            else end = mid;
        }
        return begin - 1;
    }
};