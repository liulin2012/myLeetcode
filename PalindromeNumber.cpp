//152ms
class Solution {
public:
    bool isPalindrome(int x) {
        string res = to_string(x);
        int begin = 0;
        int end = res.size() - 1;
        while (begin != end && begin - 1 !=end) {
            if (res[begin] != res[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
};

//without extra space
//119ms
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        long reverse = 0;
        while (tmp) {
            reverse = reverse*10 + tmp%10;
            tmp /= 10;
            //if (reverse > INT32_MAX) return false;
        }
        return reverse == x;
    }
};