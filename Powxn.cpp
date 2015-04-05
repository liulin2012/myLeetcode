class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        int i = n > 0 ? 1 : -1;
        n = n * i;
        double prod = 1;
        while (n) {
            if (n & 1)  prod *= x;
            x *= x;
            n /= 2;
            //n = n >> 1;
        }
        return i > 0 ? prod : 1/prod;
    }
};