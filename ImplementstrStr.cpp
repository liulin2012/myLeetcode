//Implement strStr().

//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (*needle == '\0') return 0;
        int h = 0;
        int n = 0;
        int count = 0;
        while (haystack[h] != '\0') {
            if (needle[n] == '\0') return h - count;
            if (needle[n] == haystack[h]) {
                n++;
                h++;
                count++;
            }
            else {
                h = h - count + 1;
                count = 0;
                n = 0;
            }
        }
        if (needle[n] == '\0') return h - count;
        return -1;
    }
};