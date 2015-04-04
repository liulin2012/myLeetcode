Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Show Tags

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) return 0;
        int begin = 0;
        int final = n - 1;
        while (begin != final + 1) {
            while (A[begin] != elem && begin != n) begin++;
            while (A[final] == elem && final != -1) final--;
            if (begin != final + 1)
               swap(A[begin], A[final]);
        }
        return final + 1;
    }
};