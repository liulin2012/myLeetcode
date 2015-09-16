class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1;
        long res = 0;
        while (digit <= n) {
            digit *= 10;
            long left = n / digit;
            long right = n % digit;
            res += left * digit / 10;
            if (right >= digit/5) res += digit/10;
            else if (right >= digit/10) res += right - digit/10 + 1;
            
        }
        
        return res;
    }
};