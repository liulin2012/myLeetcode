class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int c = 0, i = a.size() -1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            res = to_string(c%2) + res;
            c /= 2;
        }
        return res;
    }
};