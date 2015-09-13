class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numerator2 = numerator;
        long denominator2 = denominator;
        if (numerator == 0) return "0";
        bool positive = true;
        if (numerator < 0) {positive = !positive; numerator2 = numerator; numerator2 = numerator2 * (-1);}
        if (denominator < 0) {positive = !positive; denominator2 = denominator; denominator2 = denominator2 * (-1);}
        long front = numerator2 / denominator2;
        string res;
        if (positive) res = to_string(front);
        else res = "-" + to_string(front);
        long left = numerator2 - denominator2*front;
        if (left) res += ".";
        else return res;
        unordered_map<long, long> index;
        index[left] = 1;
        string end;
        left *= 10;
        int position = 2;
        while (left) {
            if (left < denominator2) {
                index[left] = position;
                left *= 10;
                end += "0"; 
                
            } else {
                long x = left / denominator2;
                left -= x *denominator2;
                end += to_string(x);
                
                if (index[left]) {
                position = index[left];
                res += end.substr(0, position - 1);
                res += "(";
                res += end.substr(position - 1);
                res += ")";
                return res;
                } else {index[left] = position; left *= 10;}
                
                
            }
            position++;
        }
        return res + end;
    }
};