// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long begin = 1;
        long end = n;
        while (begin < end) {
            long mid = (begin + end) / 2;
            if (!isBadVersion(mid)) begin = mid+1;
            else end = mid;
        }
        return begin;
    }
};