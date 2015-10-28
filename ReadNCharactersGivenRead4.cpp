// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char* buff;
        int rc;
        int num = 0;
        while (n > 0 && (rc = read4(buff+num)) != 0) {
            if (n < 4) rc = min(rc, n);
            
            num += rc;
            n -= rc;
        }
        return num;
            
    }
};