class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i = digits.size() - 1;
        int count = 10;
        while (count == 10 && i != -1) {
            count = 1 + digits[i];
            if (count == 10) digits[i] = 0;
            else digits[i] = count;
            i--;
        }
        if (count == 10 && i == -1) digits.insert(digits.begin(), 1);
        return digits;
    }
};


void plusone(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}