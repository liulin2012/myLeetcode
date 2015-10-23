class Solution {
public:
    string ss;
    int length;
    bool canWin(string s) {
        ss = s;
        length = s.size();
        return canWin();
    }
    bool canWin() {
        for(int i = 0; i < length - 1; i++) {
            if(ss[i] == '+' && ss[i+1] == '+') {
                ss[i] = ss[i+1] = '-';
                bool win = !canWin();
                ss[i] = ss[i+1] = '+';
                if (win) return true;
            }
        }
        return false;
    }
};