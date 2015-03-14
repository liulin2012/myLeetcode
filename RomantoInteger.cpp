/*
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        string::iterator iter = s.begin();
        while (*iter != 'I' && *iter != 'V' && iter != s.end()) {
            if (*iter == 'X') {
                iter++;
                if (*iter == 'L') result += 40;
                else if (*iter == 'C') result += 90;
                else {
                    result += 10;
                    iter--;
                }
            }
            else if (*iter == 'L') result += 50;
            else if (*iter == 'C') {
                iter++;
                if (*iter == 'D') result += 400;
                else if (*iter == 'M') result += 900;
                else {
                    result += 100;
                    iter--;
                }
            }
            else if (*iter == 'D') result += 500;
            else if (*iter == 'M') result += 1000;
            iter++;
        }
        
        string endSub;
        while (iter != s.end()) {
            endSub += *iter;
            iter++;
        }
        
        if (endSub == "I") result += 1;
        else if (endSub == "II") result += 2;
        else if (endSub == "III") result += 3;
        else if (endSub == "IV") result += 4;
        else if (endSub == "V") result += 5;
        else if (endSub == "VI") result += 6;
        else if (endSub == "VII") result += 7;
        else if (endSub == "VIII") result += 8;
        else if (endSub == "IX") result += 9;
        
        return result;
    }
}

// others solution
int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }

   return sum;
};