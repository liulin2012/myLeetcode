class Solution {
public:
    int maxProduct(int A[], int n) {
        int max = A[0];
        int countMax = A[0];
        int countMin = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] == 0) {
                countMax = 0;
                countMin = 0;
            }
            else if (A[i] > 0) {
                countMax = std::max(countMax * A[i], A[i]);
                countMin = countMin * A[i];
                max = std::max(max, countMax);
            }
            else {
                int tmp = countMin;
                countMin = std::min(countMax * A[i], A[i]);
                countMax = tmp * A[i];
                max = std::max(max, countMax);
            }
        }
        
        return max;
    }
};


class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxEnd = A[0];
        int minEnd = A[0];
        int result = A[0];
        
        for (int i = 1; i < n; i++) {
            int end1 = maxEnd * A[i];
            int end2 = minEnd * A[i];
            maxEnd = max(max(end1, end2), A[i]);
            minEnd = min(min(end1, end2), A[i]);
            result = max(result, maxEnd);
        }
        
        return result;
    }
};