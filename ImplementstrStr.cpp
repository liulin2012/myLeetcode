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


class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index = computerArray(needle);
        int i = 0;
        int j = 0;
        while (i < haystack.size()) {
            if (j == needle.size()) return i - j;
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j == 0) i++;
                else j = index[j - 1];
            }
        }
        return j == needle.size() ? i-j : -1; 
    }
    
    vector<int> computerArray(string needle) {
        vector<int> index(needle.size(), 0);
        int len = 0;
        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[len]) {
                len++;
                index[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = index[len - 1];
                } else {
                    needle[i] = 0;
                    i++;
                }
            }
        }
        return index;
    }
};