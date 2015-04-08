class Solution {
public:
    bool valid(char a) {
        int m = a - 48;
        if (m >= 0 && m <= 9) return true;
        else return false;
    }
    int atoi(string str) {
        long res = 0;
        int sign = 1;
        int begin = 0;
        while (str[begin] == ' ') begin++;
        if (str[begin] == '-') sign = -1;
        else {
            if (str[begin] == '+') ;
            else if (valid(str[begin]))
                res = str[begin] - 48;
            else return 0;
        }
        for (int i = begin + 1; i < str.size(); i++) {
            if (valid(str[i])) {
                res = res * 10 + (str[i] - 48);
                if (res*sign > INT32_MAX) return INT32_MAX;
                if (res*sign < INT32_MIN) return INT32_MIN;
            }
            else return res * sign;
        }
        return res * sign;
    }
};