class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        int index = res.size() - 1;
        for (int i = num2.size() - 1; i >= 0; i--) {
            int indextmp = index--;
            int mul2 = num2[i] - '0';
            int up = 0;
            for (int j = num1.size() - 1; j >= 0; j--) {
                int mul1 = num1[j] - '0';
                int sum = mul1 * mul2 + res[indextmp] - '0' + up;
                up = sum / 10;
                res[indextmp] = sum%10 + '0';
                indextmp--;
            }
            res[indextmp] = up + '0';
        }
        
        index = 0;
        while (index != res.size() && res[index] == '0') index++;
        return index == res.size() ? "0" : res.substr(index);
    }
};