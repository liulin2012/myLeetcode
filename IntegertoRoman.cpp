class Solution {
public:
    string intToRoman(int num) {
        string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "M", "MM", "MMM"}
                          };
        string res;
        int i = 0;
        while (num > 0) {
            int j = num % 10;
            res = table[i][j] + res;
            i++;
            num /= 10;
        }
        return res;
    }
};