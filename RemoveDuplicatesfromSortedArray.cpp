//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1,1,2],
//
//Your function should return length = 2, and A is now [1,2].
//
//Show Tags

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (A == NULL | n == 0) return 0;
        int p = 0;
        for (int i = 1; i < n; i++) {
            if (A[p] != A[i]) {
                p++;
                A[p] = A[i];
            }
        }
        return p + 1;
    }
};