// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<int> qu;
    int read(char *buf, int n) {
        int rc;
        int num = 0;
        
        while (!qu.empty()) {
            buf[num++] = qu.front();
            qu.pop();
            if (num == n) return num;
        }
        while (num < n) {
            rc = read4(buf+num);
            num += rc;
            if (rc < 4) break;
        }
        for (int i = n; i < num; i++)
            qu.push(buf[i]);
        num = min(num, n);
        buf[num] = '\n';
        return num;
    }
};