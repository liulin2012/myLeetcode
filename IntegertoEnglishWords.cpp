class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string less_ten[] =
        { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
        string less_twenty[] =
        { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        string less_hundred[] =
        { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
        
        string res;
        int index = 1;
        while (num) {
            int i = num % 1000;
            num /= 1000;
            if (i != 0) {
                string tmp;
                if (i/100 != 0) tmp += less_ten[i/100] + " Hundred";
                if (i%100 >= 20) {
                    int j = i%100;
                    j = j/10;
                    tmp += less_hundred[j];
                    if (i%10 != 0) tmp += less_ten[i%10];
                }
                else if (i%100 >=10) tmp += less_twenty[i%100 - 10];
                else tmp += less_ten[i%100];
                
                if (index == 2) tmp += " Thousand";
                else if (index == 3) tmp += " Million";
                else if (index == 4) tmp += " Billion";
                
                res = tmp + res;
            }
            index++;
        }
        res.erase(0, 1);
        return res;
    }
};