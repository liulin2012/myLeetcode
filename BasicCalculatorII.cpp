class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int res = 0;
        int num = 0;
        int tmp = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') ;
            else if (s[i] >= '0' && s[i] <= '9') 
                num = 10 * num + s[i] - '0';
            else if (s[i] == '+' || s[i] == '-') {
                res += num * sign;
                sign = (s[i] == '+' ? 1 : -1);
                num = 0;
            } else {
                tmp = num;
                int index = ++i;
                while (s[i] == ' ') i++;
                while (i < s.size() && s[i] <= '9' && s[i] >= '0') i++;
                int m = stoi(s.substr(index, i - index));
                if (s[index - 1] == '*') num = tmp * m;
                else num = tmp / m;
                i--;
            }
        }
        if (num) res += num * sign;
        return res;
    }
};