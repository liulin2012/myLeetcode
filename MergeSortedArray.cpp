Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively !3!P.


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1;
        int j = n-1;
        for (int k = m+n-1; k >= 0; k--) {
            if (i < 0)              A[k] = B[j--];
            else if (j < 0)         A[k] = A[i--];
            else if (A[i] < B[j])   A[k] = B[j--];
            else                    A[k] = A[i--];
        }
    }
};

    class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            if (n == 0) return;
            if (m == 0) { 
                while (n != 0) {
                    A[n -1] = B[n - 1];
                    n--;
                }
                return;
            }
            
            int index = m + n -1;
            while (m != 0 && n != 0) {
                if (A[m - 1] >= B[n - 1]) {
                    A[index] = A[m - 1];
                    m--;
                }else {
                    A[index] = B[n - 1];
                    n--;
                }
                index--;
            }
            
            if (n == 0) return;
            while (index != -1) {
                A[index] = B[n - 1];
                index--;
                n--;
            }
        }
    };