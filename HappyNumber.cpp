class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> result;
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            if (result.find(sum) != result.end()) return false;
            else result.insert(sum);
            n = sum;
        }
        return true;
    }
};