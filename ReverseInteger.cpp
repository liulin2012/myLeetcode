class Solution {
public:
    int reverse(int x) {
        queue<int> result;
        string a = to_string(x);
        int signal = 1;;
        for (auto w : a) {
            if (w == '-') signal = -1;
            else {
                result.push(w - 48);
            }
        }
        int64_t multi = 1;
        int64_t sum = 0;
        while (!result.empty()) {
            int tmp = result.front();
            result.pop();
            sum += tmp * multi;
            multi *= 10;
            if (sum > INT32_MAX) return 0;
        }
        
        return sum * signal;
    }
};


class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res > INT32_MAX || res < INT32_MIN) ? 0 : res;
    }
};